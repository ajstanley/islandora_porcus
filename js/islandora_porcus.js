
(function($) {
  Drupal.behaviors.IslandoraFileview = {
    attach: function(context, settings) {
      $('.porcus_thumb').click(function(){
        $('.porcus_thumb').hide('slow');
      });
    }
  };
})(jQuery);
    