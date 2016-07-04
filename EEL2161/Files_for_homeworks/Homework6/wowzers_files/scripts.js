var height_video = jQuery(window).width();
var height_responsive = (height_video / 1.78011) + 1;
jQuery('.video_slide').css("height",height_responsive);



jQuery(window).resize(function() {

var height_video = jQuery(window).width();
var height_responsive = (height_video / 1.78011) + 1;
jQuery('.video_slide').css("height",height_responsive);

});

	
var   window_height = jQuery(window).height(),
      testMobile,
	  loadingError = '<p class="error">The Content cannot be loaded.</p>',
      current,
	  next, 
	  prev,
	  target, 
	  hash,
	  url,
	  page,
	  title,	  	  	  
	  projectIndex,
	  scrollPostition,
	  projectLength,
	  ajaxLoading = false,
	  wrapperHeight,
	  pageRefresh = true,
	  content =false,
	  loader = jQuery('div#loader'),
	  portfolioGrid = jQuery('div#portfolio-wrap'),
	  projectContainer = jQuery('div#ajax-content-inner'),
	  projectNav = jQuery('#project-navigation ul'),
	  exitProject = jQuery('div#closeProject a'),
	  easing = 'easeOutExpo',
	  folderName ='portfolio-item';	
	    
	  jQuery.browser.safari = (jQuery.browser.webkit && !(/chrome/.test(navigator.userAgent.toLowerCase())));	 	

	 
	 if ( !jQuery.browser.safari ) {
		  jQuery('.home3').children('.container').addClass('no-safari');
	 }


	jQuery('.home-slide').each(function(){
	    contentSize = jQuery(this).find('.home-slide-content');  
        contentSize.fitText(1.5);			
	});

	
	 var init = function() {
	  
		  // Function to slabtext the H1 headings
		  function slabTextHeadlines() {
			  jQuery(".home-quote h1").slabText({
				   // Don't slabtext the headers if the viewport is under 479px
				  "viewportBreakpoint":300
			
			
			});
    };
	
 


    jQuery(window).load(function() {
        setTimeout(slabTextHeadlines, 5);
    });

	 
/*----------------------------------------------------*/
/* FULLSCREEN IMAGE HEIGHT
/*----------------------------------------------------*/	     
	
	  function fullscreenImgHeight(){

		  jQuery('.fullscreen, .background-video').css({height:window_height});
/*		  var headerH = jQuery('nav').outerHeight();
          jQuery("#home").css('marginBottom',-headerH);*/
		  
	  }
		  
	  fullscreenImgHeight();
		  
		  
		  
	  jQuery(window).bind('resize',function() {
	  
		  fullscreenImgHeight();
		  home_parallax();
		 		  
	  });	 
	  
/*----------------------------------------------------*/
/* FULLWIDTH SECTION
/*----------------------------------------------------*/	
	function fullWidthSection(){
		$offset_block = ((jQuery(window).width() - parseInt(jQuery('.sixteen').width())) / 2); 
		
		jQuery('.full-width').each(function(){
			
		
				jQuery(this).css({
					'margin-left': - $offset_block,
					'padding-left': $offset_block,
					'padding-right': $offset_block
				});	
			
			
		});
	}
	
	
	fullWidthSection();
	jQuery(window).resize(fullWidthSection);   	  
	  
};	


  jQuery(window).load(function(){   
  jQuery(document).ready(function($){     
// cache container
	var container = jQuery('#portfolio-wrap');	
	

	container.isotope({
		animationEngine : 'best-available',
	  	animationOptions: {
	     	duration: 200,
	     	queue: false
	   	},
		layoutMode: 'fitRows'
	});	


	// filter items when filter link is clicked
	jQuery('#filters a').click(function(){
		jQuery('#filters a').removeClass('active');
		jQuery(this).addClass('active');
		var selector = jQuery(this).attr('data-filter');
	  	container.isotope({ filter: selector });
        setProjects();		
	  	return false;
	});
		
		
		function splitColumns() { 
			var winWidth = jQuery(window).width(), 
				columnNumb = 1;
			
			
			if (winWidth > 1500) {
				columnNumb = 5;
			} else if (winWidth > 980) {
				columnNumb = 4;
			} else if (winWidth > 768) {
				columnNumb = 3;
			} else if (winWidth > 320) {
				columnNumb = 2;
			} else if (winWidth < 320) {
				columnNumb = 1;
			}
			
			return columnNumb;
		}		
		
		function setColumns() { 
			var winWidth = jQuery(window).width(), 
				columnNumb = splitColumns(), 
				postWidth = Math.floor(winWidth / columnNumb);
			
			container.find('.portfolio-item').each(function () { 
				jQuery(this).css( { 
					width : postWidth + 'px' 
				});
			});
		}		
		
		function setProjects() { 
			setColumns();
			container.isotope('reLayout');
		}		
		
		container.imagesLoaded(function () { 
			setColumns();
		});
		
	
		jQuery(window).bind('resize', function () { 
			setProjects();			
		});

});
});



function home_parallax() {
	        jQuery(window).scroll(function() {
	            var yPos = -(jQuery(window).scrollTop() / 2); 
         
	            // Put together our final background position
	            var coords = '50%'+ yPos + 'px';
	 
	            // Move the background
	            //jQuery('.page-title-wrapper').css({ backgroundPosition: coords });
	            jQuery('.home-parallax').css({ backgroundPosition: coords });
	        
	        }); 
}

 home_parallax();


/*----------------------------------------------------*/
/* MOBILE DETECT FUNCTION
/*----------------------------------------------------*/

	var isMobile = {
        Android: function() {
            return navigator.userAgent.match(/Android/i);
        },
        BlackBerry: function() {
            return navigator.userAgent.match(/BlackBerry/i);
        },
        iOS: function() {
            return navigator.userAgent.match(/iPhone|iPad|iPod/i);
        },
        Opera: function() {
            return navigator.userAgent.match(/Opera Mini/i);
        },
        Windows: function() {
            return navigator.userAgent.match(/IEMobile/i);
        },
        any: function() {
            return (isMobile.Android() || isMobile.BlackBerry() || isMobile.iOS() || isMobile.Opera() || isMobile.Windows());
        }
    };	  
	  
	 	   



	 
/*----------------------------------------------------*/
// CONTACT FORM WIDGET
/*----------------------------------------------------*/
	var contactFormDefaults=new Array();
	contactFormDefaults['contactName']=rnr_global_vars.contactFormDefaults_name;
	contactFormDefaults['contactEmail']=rnr_global_vars.contactFormDefaults_email;
	contactFormDefaults['contactSubject']=rnr_global_vars.contactFormDefaults_subject;
	contactFormDefaults['contactMessage']=rnr_global_vars.contactFormDefaults_message;
	contactFormDefaults['msg']=jQuery('.contactForm span#msg').html();
	
	jQuery('.contactForm input[type="text"], .contactForm textarea').focus(function() {
		jQuery(this).addClass('inputHighlight').removeClass('errorOutline');
		if(jQuery(this).hasClass('required')) {
			jQuery('.contactForm span#msg').html(rnr_global_vars.contact_form_required_fields_label_ajax).removeClass('errorMsg successMsg');
		} else {
			jQuery('.contactForm span#msg').html(contactFormDefaults['msg']).removeClass('errorMsg successMsg');
		}
		if(jQuery(this).val()==contactFormDefaults[jQuery(this).attr('id')]) {
			jQuery(this).val('');
		}
	});
	jQuery('.contactForm input[type="text"], .contactForm textarea').blur(function() {
		jQuery(this).removeClass('inputHighlight');
		jQuery('.contactForm span#msg').html(contactFormDefaults['msg']).removeClass('errorMsg successMsg');
		if(jQuery(this).val()=='') {
			jQuery(this).val(contactFormDefaults[jQuery(this).attr('id')]);
		}
	});
	
	jQuery('.contactForm input[type="text"], .contactForm textarea').hover(function() {
			jQuery(this).addClass('inputHighlight');
		},
		function() {	
			jQuery(this).not(':focus').removeClass('inputHighlight');
		}
	);
	
	
jQuery(document).ready(function($){
		
	$('.contactForm').submit(function() {
		$form = $('.contactForm');
		$('.contactForm .submit').attr("disabled", "disabled");
		$('#msg').html('<span class="loading-animation"></span>').removeClass('errorMsg successMsg');
		var isError=false;
		$('.contactForm input, .contactForm textarea').each(function() {
			if($(this).hasClass('required') && ($.trim($(this).val())==contactFormDefaults[$(this).attr('id')] || $.trim($(this).val())=='')) {
				$(this).addClass('errorOutline');
				$('#msg').html(rnr_global_vars.contact_form_warning).addClass('errorMsg');
				isError=true;
			}
			if($(this).attr('id')=='contactEmail') {
				var reg = /^([A-Za-z0-9_\-\.])+\@([A-Za-z0-9_\-\.])+\.([A-Za-z]{2,4})$/;
				if(reg.test($(this).val())==false) {
					$(this).addClass('errorOutline');
					if(!isError) {
						$('#msg').html(rnr_global_vars.contact_form_email_warning).addClass('errorMsg');
					}
					isError=true;
				}
			}
		});
		if(isError) {
			$('.contactForm .submit').removeAttr("disabled");
			return false;
		} else {
			var name = $('#contactName').val(), email = $('#contactEmail').val(), subject = $('#contactSubject').val(), message = $('#contactMessage').val();
			$.ajaxSetup ({
				cache: false
			});
			var str = $form.serialize();
			$.ajax({
				type: "POST",
				url: $('#contact-form').attr('action'),
				data: str,
				success: function(msg) {
					// Check to see if the mail was successfully sent

						// Update the progress bar
						$('#msg').html(rnr_global_vars.contact_form_success_message).addClass('successMsg');
												// Reset the subject field and message textbox
						if(contactFormDefaults['contactSubject']) {
							$('#contactSubject').val(contactFormDefaults['contactSubject']);
						} else {
							$('#contactSubject').val('');
						}
						if(contactFormDefaults['contactMessage']) {
							$('#contactMessage').val(contactFormDefaults['contactMessage']);
						} else {
							$('#contactMessage').val('');
						}

					// Activate the submit button
					$('.contactForm .submit').removeAttr("disabled");
				},
				error: function(ob,errStr) {
					$('#msg').html(rnr_global_vars.contact_form_error).addClass('errorMsg');
					//Activate the submit button
					$('.contactForm .submit').removeAttr("disabled");
				}
			});
			return false;
		}
	});
	
});
  

/*----------------------------------------------------*/
// LOAD PROJECT
/*----------------------------------------------------*/ 


	  
function initializePortfolio() {


  jQuery(window).bind( 'hashchange', function() {
	  
	  		 
 hash = jQuery(window.location).attr('hash'); 
 var root = '#!'+ folderName +'/';
 var rootLength = root.length;	
 
 	 
	if( hash.substr(0,rootLength) != root ){
		return;						
	} else {	

		 var correction = 50;
		 var headerH = jQuery('nav').outerHeight()+correction;
		 hash = jQuery(window.location).attr('hash'); 
	     url = hash.replace(/[#\!]/g, '' ); 
		 
		 
       
		portfolioGrid.find('div.portfolio-item.current').children().removeClass('active');
		portfolioGrid.find('div.portfolio-item.current').removeClass('current' );
		
		


		/* IF URL IS PASTED IN ADDRESS BAR AND REFRESHED */
		if(pageRefresh == true && hash.substr(0,rootLength) ==  root){	

				jQuery('html,body').stop().animate({scrollTop: (projectContainer.offset().top-20)+'px'},800,'easeOutExpo', function(){											
					loadProject();																									  
				});
				
		/* CLICKING ON PORTFOLIO GRID OR THROUGH PROJECT NAVIGATION */
		}else if(pageRefresh == false && hash.substr(0,rootLength) == root){				
					jQuery('html,body').stop().animate({scrollTop: (projectContainer.offset().top-headerH)+'px'},800,'easeOutExpo', function(){ 		
		
					if(content == false){						
						loadProject();							
					}else{	
						projectContainer.animate({opacity:0,height:wrapperHeight},function(){
						loadProject();
						});
					}
							
					projectNav.fadeOut('100');
					exitProject.fadeOut('100');
							
					});
			
		/* USING BROWSER BACK BUTTON WITHOUT REFRESHING */	
		}else if(hash=='' && pageRefresh == false || hash.substr(0,rootLength) != root && pageRefresh == false || hash.substr(0,rootLength) != root && pageRefresh == true){	
		        scrollPostition = hash; 
				console.log(scrollPostition);
				jQuery('html,body').stop().animate({scrollTop: scrollPostition+'px'},1000,function(){				
							
					deleteProject();								
							
				});
				
		/* USING BROWSER BACK BUTTON WITHOUT REFRESHING */	
		}
		
		
		
		/* ADD ACTIVE CLASS TO CURRENTLY CLICKED PROJECT */
		 portfolioGrid.find('div.portfolio-item .portfolio a[href$="#!' + url + '"]' ).parent().parent().addClass( 'current' );
		 portfolioGrid.find('div.portfolio-item.current').find('.portfolio').addClass('active');
		

	
  }
	  
	});	  
	  	/* LOAD PROJECT */		
		function loadProject(){
			loader.fadeIn().removeClass('projectError').html('<p class="icon"><i class="fa fa-spinner fa-spin fa-fw"></i></p>');
			
			
			if(!ajaxLoading) {				
	            ajaxLoading = true;
								
				projectContainer.load( url +' div#ajaxpage', function(xhr, statusText, request){
																   
						if(statusText == "success"){				
								
								ajaxLoading = false;
								
									page =  jQuery('#ajaxpage');		
			
									jQuery('.flexslider').flexslider({
												
												animation: "fade",
												direction: "horizontal",
												slideshow: true,
												slideshowSpeed: 4500,
												animationSpeed: 800,
												directionNav: true,
												controlNav: true,
												pauseOnHover: true
												
										});
			
									jQuery('#ajaxpage').waitForImages(function() {
										hideLoader();  
									});			  
											
										jQuery(".container").fitVids();	
										rnr_shortcodes();
								
						}
						
						if(statusText == "error"){
						
								loader.addClass('projectError').append(loadingError);
								
								loader.find('p').slideDown();

						}
					 
					});
				
			}
			
		}
		

		
		function hideLoader(){													  
	        loader = jQuery('div#loader'); 
			loader.delay(400).fadeOut('fast', function(){
					showProject();					
			});	
					 
		}	
		
		
		function showProject(){
			if(content==false){
				    wrapperHeight = projectContainer.children('div#ajaxpage').outerHeight()+'px';
					projectContainer.animate({opacity:1,height:wrapperHeight}, function(){
				        jQuery(".container").fitVids();
						scrollPostition = jQuery('html,body').scrollTop();
						projectNav.fadeIn();
						exitProject.fadeIn();
						content = true;	
								
					});
					
			}else{
                    wrapperHeight = projectContainer.children('div#ajaxpage').outerHeight()+'px';
					projectContainer.animate({opacity:1,height:wrapperHeight}, function(){																		  
					jQuery(".container").fitVids();
						scrollPostition = jQuery('html,body').scrollTop();
						projectNav.fadeIn();
						exitProject.fadeIn();
						
					});					
			}
					
			
			projectIndex = portfolioGrid.find('div.portfolio-item.current').index();
			projectLength = jQuery('div.portfolio-item .portfolio').length-1;
			
			
			if(projectIndex == projectLength){
				
				jQuery('ul li#nextProject a').addClass('disabled');
				jQuery('ul li#prevProject a').removeClass('disabled');
				
			}else if(projectIndex == 0){
				
				jQuery('ul li#prevProject a').addClass('disabled');
				jQuery('ul li#nextProject a').removeClass('disabled');
				
			}else{
				
				jQuery('ul li#nextProject a,ul li#prevProject a').removeClass('disabled');
				
			}
		
	  }
	  
	  
	  
	  function deleteProject(closeURL){
				projectNav.fadeOut(100);
				exitProject.fadeOut(100);				
				projectContainer.animate({opacity:0,height:'0px'});
				projectContainer.empty();
				
			if(typeof closeURL!='undefined' && closeURL!='') {
				location = '#_';
			}
			portfolioGrid.find('div.portfolio-item.current').children().removeClass('active');
			portfolioGrid.find('div.portfolio-item.current').removeClass('current' );			
	  }
	  
	  
     /* LINKING TO PREIOUS AND NEXT PROJECT VIA PROJECT NAVIGATION */
	  jQuery('#nextProject a').on('click',function () {											   							   
					 
		    current = portfolioGrid.find('.portfolio-item.current');
		    next = current.next('.portfolio-item');
		    target = jQuery(next).children('div').children('a').attr('href');
			jQuery(this).attr('href', target);
			
		
			if (next.length === 0) { 
				 return false;			  
			 } 
		   
		   current.removeClass('current'); 
		   current.children().removeClass('active');
		   next.addClass('current');
		   next.children().addClass('active');
		   
		  
		   
		});



	    jQuery('#prevProject a').on('click',function () {			
			
		  current = portfolioGrid.find('.portfolio-item.current');
		  prev = current.prev('.portfolio-item');
		  target = jQuery(prev).children('div').children('a').attr('href');
		  jQuery(this).attr('href', target);
			
		   
		   if (prev.length === 0) {
			  return false;			
		   }
		   
		   current.removeClass('current');  
		   current.children().removeClass('active');
		   prev.addClass('current');
		   prev.children().addClass('active');
		   
		});
		
		
         /* CLOSE PROJECT */
		 jQuery('#closeProject a').on('click',function () {
			 
		    deleteProject(jQuery(this).attr('href')); 			
			portfolioGrid.find('div.portfolio-item.current').children().removeClass('active');			
			loader.fadeOut();
			return false;
			
		});
		 

		 
		 pageRefresh = false;	  


};
		 

	
//BEGIN DOCUMENT.READY FUNCTION
jQuery(document).ready(function() 
{ 
  init(); 
  initializePortfolio();  
  rnr_shortcodes();
  
  jQuery(window).trigger( 'resize' );

	
jQuery("#nav").superfish({
	delay:       500,
	animation:   {opacity:'show',height:'show'},
	speed:       300,
	autoArrows:  false, 
	dropShadows: false,
});
	
  

/* ------------------------------------------------------------------------ */
/* BACK TO TOP 
/* ------------------------------------------------------------------------ */

	jQuery(window).scroll(function(){
		if(jQuery(window).scrollTop() > 800){
			jQuery("#back-to-top").fadeIn(200);
		} else{
			jQuery("#back-to-top").fadeOut(200);
		}
	});
	
	jQuery('#back-to-top, .back-to-top').click(function() {
		  jQuery('html, body').animate({ scrollTop:0 }, '800');
		  return false;
	});
		
      

/*----------------------------------------------------*/
// ADD PRETTYPHOTO
/*----------------------------------------------------*/
	jQuery("a[data-rel^='prettyPhoto']").prettyPhoto();
	
	
/*----------------------------------------------------*/
// ADD VIDEOS TO FIT ANY SCREEN
/*----------------------------------------------------*/
	 jQuery(".container").fitVids();	 		
					
  
/*----------------------------------------------------*/
// PRELOADER CALLING
/*----------------------------------------------------*/    
    jQuery("body.onepage").queryLoader2({
        barColor: "#111111",
        backgroundColor: "#ffffff",
        percentage: true,
        image: true,
        image_url: '/wp-content/themes/pixelninja/images/pixel-ninja-logo-animated.gif',
        barHeight: 5,
        completeAnimation: "fade",
        minimumTime: 200
    });  
	


/*----------------------------------------------------*/
// MENU SMOOTH SCROLLING
/*----------------------------------------------------*/  
    jQuery(".main-menu a, .logo a, .home-logo-text a, .home-logo a, .scroll-to").bind('click',function(event){
		
		var headerH = jQuery('nav.navigation').height();
		
		jQuery(".main-menu a").removeClass('active');
		jQuery(this).addClass('active');		
        jQuery("html, body").animate({
            scrollTop: jQuery(jQuery(this).attr("href")).offset().top - (headerH) + "px"
        }, {
            duration: 1200,
            easing: "easeInOutExpo"
        });

        return false;
		event.preventDefault();
    });
	



	
	jQuery('.milestone-counter').waypoint(function() {
		jQuery('.milestone-counter').each(function(){
			dataperc = jQuery(this).attr('data-perc'),
			jQuery(this).find('.milestone-count').delay(6000).countTo({
            from: 0,
            to: dataperc,
            speed: 2000,
            refreshInterval: 100
        });
     });
 	}, {
 		triggerOnce: true,
		offset: '100%'
 	});	

 
    //img overlays
    jQuery('.team-thumb').on('mouseover', function()
    {
        var overlay = jQuery(this).find('.team-overlay');
        var content = jQuery(this).find('.overlay-content');

        overlay.stop(true,true).fadeIn(600);
        content.stop().animate({'top': "40%",
			                     opacity:1 }, 600);
        
    }).on('mouseleave', function()
    {
        var overlay = jQuery(this).find('.team-overlay');
        var content = jQuery(this).find('.overlay-content');
        
        content.stop().animate({'top': "60%",
			                     opacity:0  }, 300, function(){
			content.css('top',"20%")});
			
        overlay.fadeOut(300);
		
    }); 	
  
});
//END DOCUMENT.READY FUNCTION
		


// BEGIN WINDOW.LOAD FUNCTION		
jQuery(window).load(function(){
	
	jQuery('#load').fadeOut().remove();
	jQuery(window).trigger( 'hashchange' );
	jQuery(window).trigger( 'resize' );
  jQuery('[data-spy="scroll"]').each(function () {
    var $spy = jQuery(this).scrollspy('refresh');
	
  }); 	
 
/* ------------------------------------------------------------------------ */
/* FLEX SLIDER */
/* ------------------------------------------------------------------------ */    

	 if ( jQuery.browser.safari ) {
		  jQuery('.flexslider').flexslider({						
			animation: "slide",
			direction: "horizontal", 
			slideshow: true,
			slideshowSpeed: 3500,
			animationSpeed: 800,
			directionNav: true,
			controlNav: false,	
			pauseOnHover: true,					
			useCSS: false
		  });
	 }
	jQuery('.flexslider').flexslider({						
			animation: "fade",
			direction: "horizontal", 
			slideshow: true,
			slideshowSpeed: 3500,
			animationSpeed: 800,
			directionNav: true,
			controlNav: false,
			pauseOnHover: true			
	 });
	 
/* ------------------------------------------------------------------------ */
/* Skillbar */
/* ------------------------------------------------------------------------ */	
	jQuery('.skillbar').waypoint(function() {
		jQuery('.skillbar').each(function(){
			dataperc = jQuery(this).attr('data-perc'),
			jQuery(this).find('.skill-percentage').animate({ "width" : dataperc + "%"}, dataperc*10);
		});
	 }, {
	 	triggerOnce: true,
		offset: '100%'
	 });  

/* ------------------------------------------------------------------------ */
/* TEXT FITTING FOR HOME STYLING 2 */
/* ------------------------------------------------------------------------ */ 	    
      jQuery('.home-slide-content').fitText(1.5);
	  jQuery('.fittext-content').fitText(2);
	  jQuery('.team-member').parents('.section').css('z-index','inherit');
	  jQuery('.parallax .home-quote').parents('.container').css('display','block');
 
/* ------------------------------------------------------------------------ */
/* STICKY NAVIGATION */
/* ------------------------------------------------------------------------ */ 
 
	jQuery("nav.sticky-nav").sticky({ topSpacing: 0, className: 'sticky', wrapperClassName: 'main-menu-wrapper' });
	

	if (jQuery(window).scrollTop() > jQuery(window).height()){
		jQuery('nav.transparent').addClass('scroll');		
	} else {
		jQuery('nav.transparent').removeClass('scroll');				
	}
	
	
	jQuery(window).on("scroll", function(){
		var winHeight = jQuery(window).height();
		var windowWidth = jQuery(window).width();
		var windowScroll = jQuery(window).scrollTop();
		var home_height =  jQuery('#home').outerHeight();

			if (jQuery(window).scrollTop() > home_height){
				jQuery('nav.transparent').addClass('scroll');										
			} else {
				jQuery('nav.transparent').removeClass('scroll');									
			}

		
	  });

/* ------------------------------------------------------------------------ */
/* SELECTNAV - A DROPDOWN NAVIGATION FOR SMALL SCREENS */
/* ------------------------------------------------------------------------ */ 
	selectnav('nav', {
		nested: true,
		indent: '-'
	}); 
	
 
});
// END OF WINDOW.LOAD FUNCTION

 
jQuery('#home-slider.flexslider').flexslider({						
		animation: "swing",
		direction: "vertical", 
		slideshow: true,
		slideshowSpeed: 3500,
		animationSpeed: 1000,
		directionNav: false,
		controlNav: true,
		smootheHeight:true,
		after: function(slider) {
		  slider.removeClass('loading');
		}
			
 });
  
 (function($) {
    $.fn.countTo = function(options) {
        // merge the default plugin settings with the custom options
        options = $.extend({}, $.fn.countTo.defaults, options || {});

        // how many times to update the value, and how much to increment the value on each update
        var loops = Math.ceil(options.speed / options.refreshInterval),
            increment = (options.to - options.from) / loops;

        return jQuery(this).delay(1000).each(function() {
            var _this = this,
                loopCount = 0,
                value = options.from,
                interval = setInterval(updateTimer, options.refreshInterval);

            function updateTimer() {
                value += increment;
                loopCount++;
                jQuery(_this).html(value.toFixed(options.decimals));

                if (typeof(options.onUpdate) == 'function') {
                    options.onUpdate.call(_this, value);
                }

                if (loopCount >= loops) {
                    clearInterval(interval);
                    value = options.to;

                    if (typeof(options.onComplete) == 'function') {
                        options.onComplete.call(_this, value);
                    }
                }
            }
        });
    };

    $.fn.countTo.defaults = {
        from: 0,  // the number the element should start at
        to: 100,  // the number the element should end at
        speed: 1000,  // how long it should take to count between the target numbers
        refreshInterval: 100,  // how often the element should be updated
        decimals: 0,  // the number of decimal places to show
        onUpdate: null,  // callback method for every time the element is updated,
        onComplete: null,  // callback method for when the element finishes updating
    };
	
})(jQuery);


	 
