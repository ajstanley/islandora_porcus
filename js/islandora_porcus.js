
(function($) {
  Drupal.behaviors.IslandoraPorcus = {
    attach: function(context, settings) {
      $('#porcus_image').hide();
      $('.porcus_thumb').click(function() {
        $('.porcus_thumb').hide('slow');
        $('#porcus_image').show('slow');
      });
      $('#porcus_image').click(function() {
        $('.porcus_thumb').show('slow');
        $('#porcus_image').hide('slow');
      });
    }
  };
})(jQuery);
