function getQueryStringData() {
  var matches = location.search.match(/^\?(.*)/);
  return matches ? JSON.parse(decodeURIComponent(matches[1])) : {};
}

function setFormValue(name, value) {
  var inputs = $('input[name="' + name + '"]');
  var type = inputs.attr('type');
  var methods = {
    radio: setRadioValue
  };
  var method = methods[type];
  if (method) {
    method(inputs, name, value);
  }
}

function setRadioValue(inputs, name, value) {
  var selected = inputs.filter('[value="' + value + '"]');
  selected.attr('checked', 'checked');
  selected.parent().press();
}

$.fn.press = function() {
  return this.each(function() {
    var elem = $(this);
    elem.addClass('active btn-success');
    elem.siblings().removeClass('active btn-success').addClass('btn-default');
  });
};

function initializeForm() {
  var data = getQueryStringData();
  for (var prop in data) {
    setFormValue(prop, data[prop]);
  }
  $('form').on('submit', submitForm);
  $('.btn-group').on('click', 'label', function(event) {
    $(this).press();
  });
}

function submitForm(event) {
  event.preventDefault();
  var data = {};
  $('input:checked').each(function() {
    data[this.name] = Number($(this).val());
  });
  var url = "pebblejs://close#" + encodeURIComponent(JSON.stringify(data));
  location.href = url;
}

$(initializeForm);
