// A seemingly sensible config abstraction. Works for me!
var config = (function() {
  var key = 'config';
  var defaults = {};

  // Initialize specified config keys to 0. Using ints initialized to 0
  // seems to be the easiest way to do this, at least for now.
  function initKeys(keys) {
    keys.forEach(function(key) {
      defaults[key] = 0;
    });
  }

  // Get raw configuration (or an empty object).
  function getConfig() {
    var json = localStorage.getItem(key);
    console.log('getConfig: ' + json);
    return json ? JSON.parse(json) : {};
  }

  // Store configuration.
  function setConfig(config) {
    var json = JSON.stringify(config);
    console.log('setConfig: ' + json);
    localStorage.setItem(key, json);
    return config;
  }

  // Get configuration, adding in any properties that don't exist.
  function getConfigWithDefaults() {
    var config = getConfig();
    for (var prop in defaults) {
      if (!(prop in config)) {
        config[prop] = defaults[prop];
      }
    }
    return config;
  }

  // Persist config data to the watch. If there's an error, retry.
  var persistConfigId;
  function persistConfig(obj) {
    if (persistConfigId) {
      clearTimeout(persistConfigId);
    }
    var transactionId = Pebble.sendAppMessage(
      obj,
      function(e) {
        console.log('persistConfig success (transactionId=' + e.data.transactionId + ')');
        setConfig(obj);
      },
      function(e) {
        console.log('persistConfig error (transactionId=' + e.data.transactionId + '): ' + e.error.message);
        persistConfigId = setTimeout(persistConfig.bind(null, obj), 250);
      }
    );
  }

  return {
    init: initKeys,
    get: getConfigWithDefaults,
    set: persistConfig
  };
}());


// These constants are defined in appinfo.json, face.c, pebble-js-app.js
config.init([
  'TWO_DIGIT_DATE_KEY',
  'LIGHT_BACKGROUND_KEY'
]);


var configUrl = 'https://dl.dropboxusercontent.com/u/294332/pebble/simplified/simplified.html';

Pebble.addEventListener('showConfiguration', function(event) {
  console.log('showConfiguration');
  var json = JSON.stringify(config.get());
  console.log('json => ' + json);
  var url = configUrl + '?' + encodeURIComponent(json);
  console.log('url => ' + url);
  Pebble.openURL(url);
});

Pebble.addEventListener('webviewclosed', function(event) {
  console.log('webviewclosed');
  var json = decodeURIComponent(event.response);
  console.log('json <= ' + json);
  config.set(JSON.parse(json));
});
