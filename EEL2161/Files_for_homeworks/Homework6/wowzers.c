<!DOCTYPE html>
<!-- saved from url=(0088)http://www.pixelninja.me/how-to-fix-invalid-locale-setting-in-ubuntu-14-04-in-the-cloud/ -->
<html lang="en-US" class="csstransforms csstransforms3d csstransitions js" style="height: auto;"><!--<![endif]--><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">

<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no">

<!-- PAGE TITLE -->
<title>How to Fix Invalid Locale Setting in Ubuntu 14.04 in the Cloud | Pixel Ninja - Designer, Developer, Gamer</title>

<!--[if lt IE 9]>
	<script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
<![endif]-->


<!-- Mobile Specific Metas & Favicons
========================================================= -->

<link rel="shortcut icon" href="http://www.pixelninja.me/wp-content/uploads/2014/02/favicon.ico">

<!-- WordPress Stuff
========================================================= -->
<link rel="pingback" href="http://www.pixelninja.me/xmlrpc.php">
	<!-- Google Web Fonts -->

 <link href="./wowzers_files/css" rel="stylesheet" type="text/css"><link href="./wowzers_files/css(1)" rel="stylesheet" type="text/css"><link href="./wowzers_files/css(2)" rel="stylesheet" type="text/css">

<!-- This site is optimized with the Yoast SEO plugin v3.2.5 - https://yoast.com/wordpress/plugins/seo/ -->
<link rel="canonical" href="http://www.pixelninja.me/how-to-fix-invalid-locale-setting-in-ubuntu-14-04-in-the-cloud/">
<!-- / Yoast SEO plugin. -->

<link rel="alternate" type="application/rss+xml" title="Pixel Ninja - Designer, Developer, Gamer » Feed" href="http://www.pixelninja.me/feed/">
<link rel="alternate" type="application/rss+xml" title="Pixel Ninja - Designer, Developer, Gamer » Comments Feed" href="http://www.pixelninja.me/comments/feed/">
<link rel="alternate" type="application/rss+xml" title="Pixel Ninja - Designer, Developer, Gamer » How to Fix Invalid Locale Setting in Ubuntu 14.04 in the Cloud Comments Feed" href="http://www.pixelninja.me/how-to-fix-invalid-locale-setting-in-ubuntu-14-04-in-the-cloud/feed/">
		<div class="fit-vids-style">­<style>               .fluid-width-video-wrapper {                 width: 100%;                              position: relative;                       padding: 0;                            }                                                                                   .fluid-width-video-wrapper iframe,        .fluid-width-video-wrapper object,        .fluid-width-video-wrapper embed {           position: absolute;                       top: 0;                                   left: 0;                                  width: 100%;                              height: 100%;                          }                                       </style></div><script async="" src="http://www.google-analytics.com/analytics.js"></script><script id="twitter-wjs" src="./wowzers_files/widgets.js"></script><script type="text/javascript">
			window._wpemojiSettings = {"baseUrl":"https:\/\/s.w.org\/images\/core\/emoji\/72x72\/","ext":".png","source":{"concatemoji":"http:\/\/www.pixelninja.me\/wp-includes\/js\/wp-emoji-release.min.js?ver=4.5.2"}};
			!function(a,b,c){function d(a){var c,d,e,f=b.createElement("canvas"),g=f.getContext&&f.getContext("2d"),h=String.fromCharCode;if(!g||!g.fillText)return!1;switch(g.textBaseline="top",g.font="600 32px Arial",a){case"flag":return g.fillText(h(55356,56806,55356,56826),0,0),f.toDataURL().length>3e3;case"diversity":return g.fillText(h(55356,57221),0,0),c=g.getImageData(16,16,1,1).data,d=c[0]+","+c[1]+","+c[2]+","+c[3],g.fillText(h(55356,57221,55356,57343),0,0),c=g.getImageData(16,16,1,1).data,e=c[0]+","+c[1]+","+c[2]+","+c[3],d!==e;case"simple":return g.fillText(h(55357,56835),0,0),0!==g.getImageData(16,16,1,1).data[0];case"unicode8":return g.fillText(h(55356,57135),0,0),0!==g.getImageData(16,16,1,1).data[0]}return!1}function e(a){var c=b.createElement("script");c.src=a,c.type="text/javascript",b.getElementsByTagName("head")[0].appendChild(c)}var f,g,h,i;for(i=Array("simple","flag","unicode8","diversity"),c.supports={everything:!0,everythingExceptFlag:!0},h=0;h<i.length;h++)c.supports[i[h]]=d(i[h]),c.supports.everything=c.supports.everything&&c.supports[i[h]],"flag"!==i[h]&&(c.supports.everythingExceptFlag=c.supports.everythingExceptFlag&&c.supports[i[h]]);c.supports.everythingExceptFlag=c.supports.everythingExceptFlag&&!c.supports.flag,c.DOMReady=!1,c.readyCallback=function(){c.DOMReady=!0},c.supports.everything||(g=function(){c.readyCallback()},b.addEventListener?(b.addEventListener("DOMContentLoaded",g,!1),a.addEventListener("load",g,!1)):(a.attachEvent("onload",g),b.attachEvent("onreadystatechange",function(){"complete"===b.readyState&&c.readyCallback()})),f=c.source||{},f.concatemoji?e(f.concatemoji):f.wpemoji&&f.twemoji&&(e(f.twemoji),e(f.wpemoji)))}(window,document,window._wpemojiSettings);
		</script><script src="./wowzers_files/wp-emoji-release.min.js" type="text/javascript"></script>
		<style type="text/css">
img.wp-smiley,
img.emoji {
	display: inline !important;
	border: none !important;
	box-shadow: none !important;
	height: 1em !important;
	width: 1em !important;
	margin: 0 .07em !important;
	vertical-align: -0.1em !important;
	background: none !important;
	padding: 0 !important;
}
</style>
<link rel="stylesheet" id="twiget-widget-css-css" href="./wowzers_files/twiget.css" type="text/css" media="all">
<link rel="stylesheet" id="crayon-theme-pixel-ninja-based-on-monokai-css" href="./wowzers_files/pixel-ninja-based-on-monokai.css" type="text/css" media="all">
<link rel="stylesheet" id="crayon-font-consolas-css" href="./wowzers_files/consolas.css" type="text/css" media="all">
<link rel="stylesheet" id="rnrSkeleton-css" href="./wowzers_files/skeleton.css" type="text/css" media="all">
<link rel="stylesheet" id="style-css" href="./wowzers_files/style.css" type="text/css" media="all">
<link rel="stylesheet" id="rnrFontawesome-css" href="./wowzers_files/font-awesome.css" type="text/css" media="all">
<link rel="stylesheet" id="rnrSocial-css" href="./wowzers_files/social.css" type="text/css" media="all">
<link rel="stylesheet" id="rnrFlexslider-css" href="./wowzers_files/flexslider.css" type="text/css" media="all">
<link rel="stylesheet" id="rnrPrettyPhoto-css" href="./wowzers_files/prettyPhoto.css" type="text/css" media="all">
<link rel="stylesheet" id="rnrShortcodes-css" href="./wowzers_files/shortcodes.css" type="text/css" media="all">
<link rel="stylesheet" id="rnrTheme-css" href="./wowzers_files/theme.css" type="text/css" media="all">
<link rel="stylesheet" id="rnrMedia-css" href="./wowzers_files/media.css" type="text/css" media="all">
<link rel="stylesheet" id="GoogleFonts-css" href="./wowzers_files/css(3)" type="text/css" media="all">
<script type="text/javascript" src="./wowzers_files/jquery.js"></script>
<script type="text/javascript" src="./wowzers_files/jquery-migrate.min.js"></script>
<script type="text/javascript">
/* <![CDATA[ */
var TwigetArgs = {"via":"via twigetTweetClient","LessThanMin":"less than a minute ago","AboutAMin":"about a minute ago","MinutesAgo":"twigetRelTime minutes ago","AnHourAgo":"about an hour ago","HoursAgo":"about twigetRelTime hours ago","OneDayAgo":"1 day ago","DaysAgo":"twigetRelTime days ago","isSSL":""};
/* ]]> */
</script>
<script type="text/javascript" src="./wowzers_files/twiget.js"></script>
<link rel="https://api.w.org/" href="http://www.pixelninja.me/wp-json/">
<link rel="EditURI" type="application/rsd+xml" title="RSD" href="http://www.pixelninja.me/xmlrpc.php?rsd">
<link rel="wlwmanifest" type="application/wlwmanifest+xml" href="http://www.pixelninja.me/wp-includes/wlwmanifest.xml"> 

<link rel="shortlink" href="http://www.pixelninja.me/?p=874">
<link rel="alternate" type="application/json+oembed" href="http://www.pixelninja.me/wp-json/oembed/1.0/embed?url=http%3A%2F%2Fwww.pixelninja.me%2Fhow-to-fix-invalid-locale-setting-in-ubuntu-14-04-in-the-cloud%2F">
<link rel="alternate" type="text/xml+oembed" href="http://www.pixelninja.me/wp-json/oembed/1.0/embed?url=http%3A%2F%2Fwww.pixelninja.me%2Fhow-to-fix-invalid-locale-setting-in-ubuntu-14-04-in-the-cloud%2F&amp;format=xml">
<link rel="author" href="https://plus.google.com/u/0/+RichardCabelka">
<style type="text/css">/* Hide the share buttons in portfolio section */
body.home .ssba {
display:none;
}
.ssba { 
font-style:italic;
margin-top: 20px;
}
.ssba img {
display:none;
}
.ssba a {
        margin: 5px 5px 5px 0;
	-webkit-transition: all 0.2s ease 0s;
	-moz-transition: all 0.2s ease 0s;
	-o-transition: all 0.2s ease 0s;
	transition: all 0.2s ease 0s;
	display: inline-block;
	width: 40px;
	height: 40px;
	text-indent: -9999px;
	background-position: 0px 0px;
	background-repeat: no-repeat;
}
.ssba a:hover {
	background-position: 0px -40px !important;
}
a.ssba_email_share {
	background: url(../wp-content/themes/pixelninja/images/social/icons/email.png) no-repeat 0 0 #EDEDED;
}
a.ssba_email_share:hover {
	background-color: #666666
}
a.ssba_google_share {
	background: url(../wp-content/themes/pixelninja/images/social/icons/googleplus.png) no-repeat 0 0 #EDEDED;
}
a.ssba_google_share:hover {
	background-color: #d94a39;
}
a.ssba_facebook_share {
	background: url(../wp-content/themes/pixelninja/images/social/icons/facebook.png) no-repeat 0 0 #EDEDED;
}
a.ssba_facebook_share:hover {
	background-color: #3b5998;
}
a.ssba_twitter_share {
	background: url(../wp-content/themes/pixelninja/images/social/icons/twitter.png) no-repeat 0 0 #EDEDED;
}
a.ssba_twitter_share:hover {
	background-color: #48c4d2;
}</style>		<style type="text/css">.recentcomments a{display:inline !important;padding:0 !important;margin:0 !important;}</style>
		
<!-- CUSTOM TYPOGRAPHY STYLES -->
	
<style type="text/css">

  
 					 
              				
              				
				.home-parallax { 
				   background: url('http://www.pixelninja.me/wp-content/uploads/2013/08/hong-kong-bw.jpg') center top;
				}	 
				
								
					 
								 
              				
				#bg18 { 
				   background: url('http://www.pixelninja.me/wp-content/uploads/2013/08/bruce-lee-bw.jpg');
				   background-attachment:  fixed;
				   background-size: cover;
				}	 
				
								
              				
					 
								 
              				
				#bg44 { 
				   background: url('http://www.pixelninja.me/wp-content/uploads/2013/08/birds.jpg');
				   background-attachment:  fixed;
				   background-size: cover;
				}	 
				
								
              				
					 
								 
              				
				#bg51 { 
				   background: url('http://www.pixelninja.me/wp-content/uploads/2013/08/tiger-bw.jpg');
				   background-attachment:  fixed;
				   background-size: cover;
				}	 
				
								
              				
					 
								 
              				
				#bg58 { 
				   background: url('http://www.pixelninja.me/wp-content/uploads/2013/08/dojo.jpg');
				   background-attachment:  fixed;
				   background-size: cover;
				}	 
				
								
              				
					 
			 
 





body{ 
		
        		font-family: Open Sans, Arial, Helvetica, sans-serif !important; 
				font-size: 15px; 
		
				font-style: normal; 		  
			   
	   
	   color: #444444;
	   font-weight:  normal;
}

	h1{
        		font-family: Cabin, Arial, Helvetica, sans-serif !important; 
				font-size: 80px; 

				font-style: normal; 		  
		
		color: #444444; 
	    font-weight:  normal; 
	    text-transform:  uppercase;	
	}
	
	
	h2{ 
        		font-family: Cabin, Arial, Helvetica, sans-serif !important; 
				font-size: 40px; 

				font-style: normal; 		  
		
		color: #444444;  
	    font-weight:  normal; 
	    text-transform:  uppercase;	
	}
	h3{ 
        		font-family: Cabin, Arial, Helvetica, sans-serif !important; 
				font-size: 30px; 
		
				font-style: normal; 		  
		
		color: #444444;  
	    font-weight:  normal; 
	    text-transform:  uppercase;	
	}
	h4{ 
        		font-family: Cabin, Arial, Helvetica, sans-serif !important; 
				font-size: 24px; 

				font-style: normal;  
	    font-weight:  normal; 
	    text-transform:  uppercase;			  
		
		color: #444444; 
	}
	h5{ 
        		font-family: Cabin, Arial, Helvetica, sans-serif !important; 
				font-size: 22px; 

				font-style: normal; 		  
		
		color: #444444;  
	    font-weight:  normal; 
	    text-transform:  uppercase;	
	}
	h6{ 
	
        		font-family: Cabin, Arial, Helvetica, sans-serif !important; 
					

		font-size: 20px; 

				font-style: normal; 	 
	    font-weight:  normal; 
	    text-transform:  uppercase;	  
		
		color: #444444; 
	}
	
	.subtitle { 
	
        		font-family: Open Sans, Arial, Helvetica, sans-serif !important; 
				font-size: 25px; 

				font-style: normal; 	 
	    font-weight:  normal; 
	    text-transform:  none;	  
		
		color: #444444; 
	}



.navigation li a,
.navigation.colored li a,
nav.light .main-menu a,
nav.transparent a,
nav.transparent.scroll a  {
        		 font-family: Cabin, Arial, Helvetica, sans-serif;
		 
		
		font-size: 17px; 
				font-style: normal; 		  
			   
	   
	   color: #333333;	
	   font-weight:  bold; 
	   text-transform:  uppercase;   	   	
}
.navigation li a:hover, 
.navigation li.active a ,
.navigation.colored li a:hover, 
.navigation.colored li.active a, 
.navigation li.current-menu-item a{
	   color: #ffffff !important;	   
}

.navigation.transparent li.current-menu-item a,
.navigation.transparent li.active a {
	   color: #ffd600 !important;	   
}


.copyright {
	background: #ffd600 !important;
        	
	      font-family: Lato, Arial, Helvetica, sans-serif; 
	    	font-size: 13px; 
	
		font-style: normal; 		  
		  
   
   color: #333333;		
}
.copyright a, .copyright .social-icons .social-icon {
	   color: ;	   
}
.copyright a:hover {
	   color: #ffffff;	   
}








/*========== B A C K G R O U N D    S K I N S =============*/

::-moz-selection {
 background: #ffd600;
}
::selection {
	background:#ffd600;
}

nav.colored, nav.light.colored,
.twitter-feed-icon i,
.testimonial-icon i,
.home-gradient,
.home-parallax,
#project-navigation ul li#prevProject a:hover, 
#project-navigation ul li#nextProject a:hover,
#project-navigation ul li a:hover,
#closeProject a:hover,
.mc4wp-form input[type="submit"]:hover,
#respond input[type="submit"]:hover,
input[type="submit"]:hover,
.pagination a.previous:hover, 
.pagination a.next:hover,
.rnr-icon-middle:hover,
.service-box:hover,
.button:hover,
.skillbar .skill-percentage,
.flex-control-nav li a:hover,
.flex-control-nav li a.flex-active,
.testimonial-slider .flex-direction-nav li a, 
.twitter-slider .flex-direction-nav li a,
.color-block,
.home1 .slabtextdone .slabtext.second-child,
.home4 .slabtextdone .slabtext.second-child,
.caption,
.copyright,
.title h1,
.service-features .img-container,
.service-features .img-container,
.view-profile,
.team-member:hover .team-desc,
.service-box .service-icon,
.modal .close,
#nav .sub-menu li.current-menu-item a, 
#nav .sub-menu li.current-menu-item a:hover, 
#nav .sub-menu li.current_page_item a, 
#nav .sub-menu li.current_page_item a:hover, 
#nav .sub-menu li .sub-menu li.current-menu-item a, 
#nav .sub-menu li .sub-menu li.current-menu-item a:hover, 
#nav .sub-menu li .sub-menu li.current_page_item a, 
#nav .sub-menu li .sub-menu li.current_page_item a:hover, 
#nav .sub-menu li a.active, #nav .sub-menu li a.active:hover {
	background-color: #ffd600;
}


/*========== B O X   S H A D O W    S K I N S =============*/

.title h1,
.service-box .service-icon {
	box-shadow:0px 0px 0px 3px #ffd600;
}

.tab a.selected {
    box-shadow: 0px -3px 0px 0px #ffd600;
}




/*========== C O L O R    S K I N S =============*/

.highlight,
nav.light .main-menu a:hover, 
nav.dark .main-menu a:hover,
nav.light .main-menu li.active a,
nav.transparent .main-menu li.active a, 
nav.dark .main-menu li.active a,
.parallax .quote i,
#filters ul li a:hover h3, 
#filters ul li a.active h3,
.post-title a:hover h2,
.post-quote a:hover,
.post-tags li a:hover,
.tags-list li a:hover,
.pages li a:hover,
.home3 .slabtextdone .slabtext.second-child,
.service-box:hover .service-icon {
	color:#ffd600;
}

a {
	color: #e5c100;
}

a:hover {
	color: #ffd600;
}


/*========== B O R D E R    S K I N S =============*/

.pages li a.current,
.pages li a.current,
.service-features .img-container:after,
.service-box:hover .service-icon,
.callout,
blockquote p,
.pullquote.align-right,
.pullquote.align-left {
	border-color: #ffd600;
}









</style>


<script type="text/javascript" charset="utf-8" async="" src="./wowzers_files/button.f680cf5c26b82452053ff9b460077fa3.js"></script></head>

<body class="single single-post postid-874 single-format-standard onepage slabtexted" data-spy="scroll" data-target=".navigation">
 
 
     <!-- START PAGE WRAP -->    
    <div class="page-wrap ">
    
  <!-- HEADER SECTION -->	
 

 

  


    <!-- START NAVIGATION -->
    <div id="undefined-sticky-wrapper" class="main-menu-wrapper sticky" style="height: 80px;"><nav class="navigation colored sticky-nav sticky" style="position: fixed; top: 0px;">
     <!-- START CONTAINER -->	
      <div class="container clearfix">			
          <div class="four columns">			
              <!-- START LOGO -->	
              <div class="logo large">
			    						<h1><a href="http://www.pixelninja.me/#" class="">Pixel Ninja – Designer, Developer, Gamer</a></h1>
					              </div>
              <!-- END LOGO -->			
          </div><!-- END FOUR COLUMNS -->                
         
           <!-- BEGIN NAVIGATION SECTION --> 
          <div class="twelve columns">            		
              <!-- START NAVIGATION MENU ITEMS -->

              <ul id="nav" class="main-menu large nav sf-menu sf-js-enabled"><li id="menu-item-135" class="menu-item menu-item-type-post_type menu-item-object-page"><a href="http://www.pixelninja.me/#home"><span>Home</span></a></li>
<li id="menu-item-134" class="menu-item menu-item-type-post_type menu-item-object-page"><a href="http://www.pixelninja.me/#introduction"><span>Intro</span></a></li>

<li id="menu-item-139" class="menu-item menu-item-type-post_type menu-item-object-page"><a href="http://www.pixelninja.me/#services"><span>Services</span></a></li>

<li id="menu-item-137" class="menu-item menu-item-type-post_type menu-item-object-page"><a href="http://www.pixelninja.me/#about-me"><span>About Me</span></a></li>

<li id="menu-item-141" class="menu-item menu-item-type-post_type menu-item-object-page"><a href="http://www.pixelninja.me/#portfolio"><span>Portfolio</span></a></li>

<li id="menu-item-144" class="menu-item menu-item-type-post_type menu-item-object-page current_page_parent"><a href="http://www.pixelninja.me/blog/"><span>Blog</span></a></li>
<li id="menu-item-143" class="menu-item menu-item-type-post_type menu-item-object-page"><a href="http://www.pixelninja.me/#contact"><span>Contact</span></a></li>

</ul><select class="selectnav" id="selectnav1"><option value="">Menu</option><option value="http://www.pixelninja.me/#home">HOME</option><option value="http://www.pixelninja.me/#introduction">INTRO</option><option value="http://www.pixelninja.me/#services">SERVICES</option><option value="http://www.pixelninja.me/#about-me">ABOUT ME</option><option value="http://www.pixelninja.me/#portfolio">PORTFOLIO</option><option value="http://www.pixelninja.me/blog/">BLOG</option><option value="http://www.pixelninja.me/#contact">CONTACT</option></select>
              <!-- END NAVIGATION MENU ITEMS -->				
          </div><!-- END TWELVE COLUMNS -->	
      </div><!-- END CONTAINER -->	
    </nav></div>
    <!-- END NAVIGATION -->
  


    <div class="section post-single"><!-- SECTION -->


		<div class="container">	
           <div class="row">	
			<div class="sixteen columns">            
	            <!-- START TITLE -->	            
				<div class="title">
				  <h1 class="header-text">How to Fix Invalid Locale Setting in Ubuntu 14.04 in the Cloud</h1>
                </div><!-- END TITLE -->  	                           
			</div><!-- END SIXTEEN COLUMNS -->  
           </div><!-- END ROW -->         
          </div><!-- END CONTAINER -->  
  


      <div class="container">   
            <div class="row">        
                <div class="twelve columns">                

                    <div class="post clearfix">

		<div class="post-image">
		<a href="./wowzers_files/ubuntu-in-the-cloud.jpg" title="How to Fix Invalid Locale Setting in Ubuntu 14.04 in the Cloud" data-rel="prettyPhoto">
			<img width="700" height="300" src="./wowzers_files/ubuntu-in-the-cloud.jpg" class="attachment-full size-full wp-post-image" alt="Ubuntu in the Cloud" srcset="http://www.pixelninja.me/wp-content/uploads/2014/06/ubuntu-in-the-cloud.jpg 700w, http://www.pixelninja.me/wp-content/uploads/2014/06/ubuntu-in-the-cloud-300x128.jpg 300w" sizes="(max-width: 700px) 100vw, 700px">		</a>
	</div>
		
	<div class="post-single-content">
		<div class="post-single-meta"><p class="meta-date">
  Posted on June 4, 2014 in <a href="http://www.pixelninja.me/category/development/" rel="category tag">Development</a></p>
 </div>	
		<div class="post-excerpt"><p>If you use Ubuntu in the cloud, specifically in AWS, you may see this warning message after SSHing into your server:</p>
<p></p><!-- Crayon Syntax Highlighter v_2.7.2_beta -->

		<div id="crayon-5746d2d6e88c1769574938" class="crayon-syntax crayon-theme-pixel-ninja-based-on-monokai crayon-font-consolas crayon-os-pc print-yes notranslate" data-settings=" minimize scroll-mouseover" style="margin-bottom: 10px; float: left; font-size: 16px !important; line-height: 20px !important; height: auto;">
		
			<div class="crayon-toolbar" data-settings=" mouseover hide" style="font-size: 16px !important; height: 24px !important; line-height: 24px !important; margin-top: -29px; display: none; z-index: 4;"><span class="crayon-title"></span>
			<div class="crayon-tools" style="font-size: 16px !important;height: 24px !important; line-height: 24px !important;"><div class="crayon-button crayon-nums-button crayon-pressed" title="Toggle Line Numbers"><div class="crayon-button-icon"></div></div><div class="crayon-button crayon-plain-button" title="Toggle Plain Code"><div class="crayon-button-icon"></div></div><div class="crayon-button crayon-wrap-button" title="Toggle Line Wrap"><div class="crayon-button-icon"></div></div><div class="crayon-button crayon-expand-button" title="Expand Code" style="display: none;"><div class="crayon-button-icon"></div></div><div class="crayon-button crayon-copy-button" title="Copy"><div class="crayon-button-icon"></div></div><div class="crayon-button crayon-popup-button" title="Open Code In New Window"><div class="crayon-button-icon"></div></div></div></div>
			<div class="crayon-info" style="min-height: 22.4px !important; line-height: 22.4px !important;"></div>
			<div class="crayon-plain-wrap"><textarea wrap="soft" class="crayon-plain print-no" data-settings="dblclick" readonly="" style="tab-size: 4; font-size: 16px !important; line-height: 20px !important; z-index: 0; opacity: 0; overflow: hidden;">WARNING! Your environment specifies an invalid locale.
This can affect your user experience significantly, including the
ability to manage packages.</textarea></div>
			<div class="crayon-main" style="position: relative; z-index: 1; overflow: hidden;">
				<table class="crayon-table">
					<tbody><tr class="crayon-row">
				<td class="crayon-nums " data-settings="show">
					<div class="crayon-nums-content" style="font-size: 16px !important; line-height: 20px !important;"><div class="crayon-num" data-line="crayon-5746d2d6e88c1769574938-1">1</div><div class="crayon-num crayon-striped-num" data-line="crayon-5746d2d6e88c1769574938-2">2</div><div class="crayon-num" data-line="crayon-5746d2d6e88c1769574938-3">3</div></div>
				</td>
						<td class="crayon-code"><div class="crayon-pre" style="font-size: 16px !important; line-height: 20px !important; -moz-tab-size:4; -o-tab-size:4; -webkit-tab-size:4; tab-size:4;"><div class="crayon-line" id="crayon-5746d2d6e88c1769574938-1"><span class="crayon-v">WARNING</span><span class="crayon-o">!</span><span class="crayon-h"> </span><span class="crayon-e">Your </span><span class="crayon-e">environment </span><span class="crayon-e">specifies </span><span class="crayon-e">an </span><span class="crayon-e">invalid </span><span class="crayon-v">locale</span><span class="crayon-sy">.</span></div><div class="crayon-line crayon-striped-line" id="crayon-5746d2d6e88c1769574938-2"><span class="crayon-r">This</span><span class="crayon-h"> </span><span class="crayon-e">can </span><span class="crayon-e">affect </span><span class="crayon-e">your </span><span class="crayon-e">user </span><span class="crayon-e">experience </span><span class="crayon-v">significantly</span><span class="crayon-sy">,</span><span class="crayon-h"> </span><span class="crayon-e">including </span><span class="crayon-e">the</span></div><div class="crayon-line" id="crayon-5746d2d6e88c1769574938-3"><span class="crayon-e">ability </span><span class="crayon-st">to</span><span class="crayon-h"> </span><span class="crayon-e">manage </span><span class="crayon-v">packages</span><span class="crayon-sy">.</span></div></div></td>
					</tr>
				</tbody></table>
			</div>
		</div>
<!-- [Format Time: 0.0011 seconds] -->
<p></p>
<p>If you than try to install any new packages with 
			<span id="crayon-5746d2d6e88d2173665477" class="crayon-syntax crayon-syntax-inline  crayon-theme-pixel-ninja-based-on-monokai crayon-theme-pixel-ninja-based-on-monokai-inline crayon-font-consolas" style="font-size: 16px !important; line-height: 20px !important;font-size: 16px !important;"><span class="crayon-pre crayon-code" style="font-size: 16px !important; line-height: 20px !important;font-size: 16px !important; -moz-tab-size:4; -o-tab-size:4; -webkit-tab-size:4; tab-size:4;"><span class="crayon-v">apt</span><span class="crayon-o">-</span><span class="crayon-v">get</span></span></span> or even restart/reload an existing service, you may get this error message: </p>
<p></p><!-- Crayon Syntax Highlighter v_2.7.2_beta -->

		<div id="crayon-5746d2d6e88d9446225971" class="crayon-syntax crayon-theme-pixel-ninja-based-on-monokai crayon-font-consolas crayon-os-pc print-yes notranslate" data-settings=" minimize scroll-mouseover" style="margin-bottom: 10px; float: left; font-size: 16px !important; line-height: 20px !important; height: auto;">
		
			<div class="crayon-toolbar" data-settings=" mouseover hide" style="font-size: 16px !important; height: 24px !important; line-height: 24px !important; margin-top: -29px; display: none; z-index: 4;"><span class="crayon-title"></span>
			<div class="crayon-tools" style="font-size: 16px !important;height: 24px !important; line-height: 24px !important;"><div class="crayon-button crayon-nums-button crayon-pressed" title="Toggle Line Numbers"><div class="crayon-button-icon"></div></div><div class="crayon-button crayon-plain-button" title="Toggle Plain Code"><div class="crayon-button-icon"></div></div><div class="crayon-button crayon-wrap-button" title="Toggle Line Wrap"><div class="crayon-button-icon"></div></div><div class="crayon-button crayon-expand-button" title="Expand Code"><div class="crayon-button-icon"></div></div><div class="crayon-button crayon-copy-button" title="Copy"><div class="crayon-button-icon"></div></div><div class="crayon-button crayon-popup-button" title="Open Code In New Window"><div class="crayon-button-icon"></div></div></div></div>
			<div class="crayon-info" style="min-height: 22.4px !important; line-height: 22.4px !important;"></div>
			<div class="crayon-plain-wrap"><textarea wrap="soft" class="crayon-plain print-no" data-settings="dblclick" readonly="" style="tab-size: 4; font-size: 16px !important; line-height: 20px !important; z-index: 0; opacity: 0; overflow: hidden;">perl: warning: Setting locale failed.   
perl: warning: Please check that your locale settings:   
        LANGUAGE = "en_US:en",   
        LC_ALL = (unset),   
        LC_MESSAGES = "en_US.UTF-8",   
        LANG = "en_US.UTF-8"   
    are supported and installed on your system.   
perl: warning: Falling back to the standard locale ("C").   
locale: Cannot set LC_CTYPE to default locale: No such file or directory   
locale: Cannot set LC_MESSAGES to default locale: No such file or directory   
locale: Cannot set LC_ALL to default locale: No such file or directory  </textarea></div>
			<div class="crayon-main" style="position: relative; z-index: 1; overflow: hidden;">
				<table class="crayon-table">
					<tbody><tr class="crayon-row">
				<td class="crayon-nums " data-settings="show">
					<div class="crayon-nums-content" style="font-size: 16px !important; line-height: 20px !important;"><div class="crayon-num" data-line="crayon-5746d2d6e88d9446225971-1">1</div><div class="crayon-num crayon-striped-num" data-line="crayon-5746d2d6e88d9446225971-2">2</div><div class="crayon-num" data-line="crayon-5746d2d6e88d9446225971-3">3</div><div class="crayon-num crayon-striped-num" data-line="crayon-5746d2d6e88d9446225971-4">4</div><div class="crayon-num" data-line="crayon-5746d2d6e88d9446225971-5">5</div><div class="crayon-num crayon-striped-num" data-line="crayon-5746d2d6e88d9446225971-6">6</div><div class="crayon-num" data-line="crayon-5746d2d6e88d9446225971-7">7</div><div class="crayon-num crayon-striped-num" data-line="crayon-5746d2d6e88d9446225971-8">8</div><div class="crayon-num" data-line="crayon-5746d2d6e88d9446225971-9">9</div><div class="crayon-num crayon-striped-num" data-line="crayon-5746d2d6e88d9446225971-10">10</div><div class="crayon-num" data-line="crayon-5746d2d6e88d9446225971-11">11</div></div>
				</td>
						<td class="crayon-code"><div class="crayon-pre" style="font-size: 16px !important; line-height: 20px !important; -moz-tab-size:4; -o-tab-size:4; -webkit-tab-size:4; tab-size:4;"><div class="crayon-line" id="crayon-5746d2d6e88d9446225971-1"><span class="crayon-v">perl</span><span class="crayon-o">:</span><span class="crayon-h"> </span><span class="crayon-v">warning</span><span class="crayon-o">:</span><span class="crayon-h"> </span><span class="crayon-e">Setting </span><span class="crayon-e">locale </span><span class="crayon-v">failed</span><span class="crayon-sy">.</span><span class="crayon-h">&nbsp;&nbsp; </span></div><div class="crayon-line crayon-striped-line" id="crayon-5746d2d6e88d9446225971-2"><span class="crayon-v">perl</span><span class="crayon-o">:</span><span class="crayon-h"> </span><span class="crayon-v">warning</span><span class="crayon-o">:</span><span class="crayon-h"> </span><span class="crayon-e">Please </span><span class="crayon-e">check </span><span class="crayon-e">that </span><span class="crayon-e">your </span><span class="crayon-e">locale </span><span class="crayon-v">settings</span><span class="crayon-o">:</span><span class="crayon-h">&nbsp;&nbsp; </span></div><div class="crayon-line" id="crayon-5746d2d6e88d9446225971-3"><span class="crayon-h">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span class="crayon-v">LANGUAGE</span><span class="crayon-h"> </span><span class="crayon-o">=</span><span class="crayon-h"> </span><span class="crayon-s">"en_US:en"</span><span class="crayon-sy">,</span><span class="crayon-h">&nbsp;&nbsp; </span></div><div class="crayon-line crayon-striped-line" id="crayon-5746d2d6e88d9446225971-4"><span class="crayon-h">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span class="crayon-v">LC_ALL</span><span class="crayon-h"> </span><span class="crayon-o">=</span><span class="crayon-h"> </span><span class="crayon-sy">(</span><span class="crayon-v">unset</span><span class="crayon-sy">)</span><span class="crayon-sy">,</span><span class="crayon-h">&nbsp;&nbsp; </span></div><div class="crayon-line" id="crayon-5746d2d6e88d9446225971-5"><span class="crayon-h">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span class="crayon-v">LC_MESSAGES</span><span class="crayon-h"> </span><span class="crayon-o">=</span><span class="crayon-h"> </span><span class="crayon-s">"en_US.UTF-8"</span><span class="crayon-sy">,</span><span class="crayon-h">&nbsp;&nbsp; </span></div><div class="crayon-line crayon-striped-line" id="crayon-5746d2d6e88d9446225971-6"><span class="crayon-h">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span class="crayon-v">LANG</span><span class="crayon-h"> </span><span class="crayon-o">=</span><span class="crayon-h"> </span><span class="crayon-s">"en_US.UTF-8"</span><span class="crayon-h">&nbsp;&nbsp; </span></div><div class="crayon-line" id="crayon-5746d2d6e88d9446225971-7"><span class="crayon-h">&nbsp;&nbsp;&nbsp;&nbsp;</span><span class="crayon-e">are </span><span class="crayon-e">supported </span><span class="crayon-st">and</span><span class="crayon-h"> </span><span class="crayon-e">installed </span><span class="crayon-e">on </span><span class="crayon-e">your </span><span class="crayon-v">system</span><span class="crayon-sy">.</span><span class="crayon-h">&nbsp;&nbsp; </span></div><div class="crayon-line crayon-striped-line" id="crayon-5746d2d6e88d9446225971-8"><span class="crayon-v">perl</span><span class="crayon-o">:</span><span class="crayon-h"> </span><span class="crayon-v">warning</span><span class="crayon-o">:</span><span class="crayon-h"> </span><span class="crayon-e">Falling </span><span class="crayon-e">back </span><span class="crayon-st">to</span><span class="crayon-h"> </span><span class="crayon-e">the </span><span class="crayon-e">standard </span><span class="crayon-e">locale</span><span class="crayon-h"> </span><span class="crayon-sy">(</span><span class="crayon-s">"C"</span><span class="crayon-sy">)</span><span class="crayon-sy">.</span><span class="crayon-h">&nbsp;&nbsp; </span></div><div class="crayon-line" id="crayon-5746d2d6e88d9446225971-9"><span class="crayon-v">locale</span><span class="crayon-o">:</span><span class="crayon-h"> </span><span class="crayon-e">Cannot </span><span class="crayon-e">set </span><span class="crayon-e">LC_CTYPE </span><span class="crayon-st">to</span><span class="crayon-h"> </span><span class="crayon-st">default</span><span class="crayon-h"> </span><span class="crayon-v">locale</span><span class="crayon-o">:</span><span class="crayon-h"> </span><span class="crayon-e">No </span><span class="crayon-e">such </span><span class="crayon-e">file </span><span class="crayon-st">or</span><span class="crayon-h"> </span><span class="crayon-e">directory&nbsp;&nbsp; </span></div><div class="crayon-line crayon-striped-line" id="crayon-5746d2d6e88d9446225971-10"><span class="crayon-v">locale</span><span class="crayon-o">:</span><span class="crayon-h"> </span><span class="crayon-e">Cannot </span><span class="crayon-e">set </span><span class="crayon-e">LC_MESSAGES </span><span class="crayon-st">to</span><span class="crayon-h"> </span><span class="crayon-st">default</span><span class="crayon-h"> </span><span class="crayon-v">locale</span><span class="crayon-o">:</span><span class="crayon-h"> </span><span class="crayon-e">No </span><span class="crayon-e">such </span><span class="crayon-e">file </span><span class="crayon-st">or</span><span class="crayon-h"> </span><span class="crayon-e">directory&nbsp;&nbsp; </span></div><div class="crayon-line" id="crayon-5746d2d6e88d9446225971-11"><span class="crayon-v">locale</span><span class="crayon-o">:</span><span class="crayon-h"> </span><span class="crayon-e">Cannot </span><span class="crayon-e">set </span><span class="crayon-e">LC_ALL </span><span class="crayon-st">to</span><span class="crayon-h"> </span><span class="crayon-st">default</span><span class="crayon-h"> </span><span class="crayon-v">locale</span><span class="crayon-o">:</span><span class="crayon-h"> </span><span class="crayon-e">No </span><span class="crayon-e">such </span><span class="crayon-e">file </span><span class="crayon-st">or</span><span class="crayon-h"> </span><span class="crayon-i">directory</span><span class="crayon-h">&nbsp;&nbsp;</span></div></div></td>
					</tr>
				</tbody></table>
			</div>
		</div>
<!-- [Format Time: 0.0038 seconds] -->
<p></p>
<p>The fix is pretty simple. Edit the 
			<span id="crayon-5746d2d6e88e1258344428" class="crayon-syntax crayon-syntax-inline  crayon-theme-pixel-ninja-based-on-monokai crayon-theme-pixel-ninja-based-on-monokai-inline crayon-font-consolas" style="font-size: 16px !important; line-height: 20px !important;font-size: 16px !important;"><span class="crayon-pre crayon-code" style="font-size: 16px !important; line-height: 20px !important;font-size: 16px !important; -moz-tab-size:4; -o-tab-size:4; -webkit-tab-size:4; tab-size:4;"><span class="crayon-o">/</span><span class="crayon-v">etc</span><span class="crayon-o">/</span><span class="crayon-v">environment</span></span></span> file and put this line at the end of it: </p>
<p>
			<span id="crayon-5746d2d6e88e7089193781" class="crayon-syntax crayon-syntax-inline  crayon-theme-pixel-ninja-based-on-monokai crayon-theme-pixel-ninja-based-on-monokai-inline crayon-font-consolas" style="font-size: 16px !important; line-height: 20px !important;font-size: 16px !important;"><span class="crayon-pre crayon-code" style="font-size: 16px !important; line-height: 20px !important;font-size: 16px !important; -moz-tab-size:4; -o-tab-size:4; -webkit-tab-size:4; tab-size:4;"><span class="crayon-v">LC_ALL</span><span class="crayon-o">=</span><span class="crayon-s">"en_US.UTF-8"</span></span></span></p>
<p>Save the file, log out and log back into you instance. You should be good. If that doesn’t work, you can try to put these lines in 
			<span id="crayon-5746d2d6e88ee466970236" class="crayon-syntax crayon-syntax-inline  crayon-theme-pixel-ninja-based-on-monokai crayon-theme-pixel-ninja-based-on-monokai-inline crayon-font-consolas" style="font-size: 16px !important; line-height: 20px !important;font-size: 16px !important;"><span class="crayon-pre crayon-code" style="font-size: 16px !important; line-height: 20px !important;font-size: 16px !important; -moz-tab-size:4; -o-tab-size:4; -webkit-tab-size:4; tab-size:4;"><span class="crayon-o">/</span><span class="crayon-v">etc</span><span class="crayon-o">/</span><span class="crayon-st">default</span><span class="crayon-o">/</span><span class="crayon-v">locale</span></span></span> instead:</p>
<p>
			<span id="crayon-5746d2d6e88f4110761415" class="crayon-syntax crayon-syntax-inline  crayon-theme-pixel-ninja-based-on-monokai crayon-theme-pixel-ninja-based-on-monokai-inline crayon-font-consolas" style="font-size: 16px !important; line-height: 20px !important;font-size: 16px !important;"><span class="crayon-pre crayon-code" style="font-size: 16px !important; line-height: 20px !important;font-size: 16px !important; -moz-tab-size:4; -o-tab-size:4; -webkit-tab-size:4; tab-size:4;"><span class="crayon-v">LANG</span><span class="crayon-o">=</span><span class="crayon-s">"en_US.UTF-8"</span></span></span><br>

			<span id="crayon-5746d2d6e88f9164489268" class="crayon-syntax crayon-syntax-inline  crayon-theme-pixel-ninja-based-on-monokai crayon-theme-pixel-ninja-based-on-monokai-inline crayon-font-consolas" style="font-size: 16px !important; line-height: 20px !important;font-size: 16px !important;"><span class="crayon-pre crayon-code" style="font-size: 16px !important; line-height: 20px !important;font-size: 16px !important; -moz-tab-size:4; -o-tab-size:4; -webkit-tab-size:4; tab-size:4;"><span class="crayon-v">LC_ALL</span><span class="crayon-o">=</span><span class="crayon-s">"en_US.UTF-8"</span></span></span></p>
<!-- Simple Share Buttons Adder (6.1.5) simplesharebuttons.com --><div class="ssba ssba-wrap"><div style="text-align:left">Enjoyed this post? Share it with others.<br><a data-site="email" class="ssba_email_share" href="mailto:?subject=How%20to%20Fix%20Invalid%20Locale%20Setting%20in%20Ubuntu%2014.04%20in%20the%20Cloud&amp;body=%20http://www.pixelninja.me/how-to-fix-invalid-locale-setting-in-ubuntu-14-04-in-the-cloud/"><img src="./wowzers_files/email.png" title="Email" class="ssba ssba-img" alt="Email this to someone"></a><a data-site="" class="ssba_facebook_share" href="http://www.facebook.com/sharer.php?u=http://www.pixelninja.me/how-to-fix-invalid-locale-setting-in-ubuntu-14-04-in-the-cloud/" target="_blank"><img src="./wowzers_files/facebook.png" title="Facebook" class="ssba ssba-img" alt="Share on Facebook"></a><a data-site="" class="ssba_google_share" href="https://plus.google.com/share?url=http://www.pixelninja.me/how-to-fix-invalid-locale-setting-in-ubuntu-14-04-in-the-cloud/" target="_blank"><img src="./wowzers_files/google.png" title="Google+" class="ssba ssba-img" alt="Share on Google+"></a><a data-site="" class="ssba_twitter_share" href="http://twitter.com/share?url=http://www.pixelninja.me/how-to-fix-invalid-locale-setting-in-ubuntu-14-04-in-the-cloud/&amp;text=How+to+Fix+Invalid+Locale+Setting+in+Ubuntu+14.04+in+the+Cloud+" target="_blank"><img src="./wowzers_files/twitter.png" title="Twitter" class="ssba ssba-img" alt="Tweet about this on Twitter"></a></div></div></div>		
             
        <div class="post-tags styled-list">
            <ul>
                <ul> <li><i class="fa fa-tag fa-fw"></i> <a href="http://www.pixelninja.me/tag/aws/" rel="tag">aws</a></li><li><i class="fa fa-tag fa-fw"></i> <a href="http://www.pixelninja.me/tag/cloud/" rel="tag">cloud</a></li><li><i class="fa fa-tag fa-fw"></i> <a href="http://www.pixelninja.me/tag/ec2/" rel="tag">ec2</a></li><li><i class="fa fa-tag fa-fw"></i> <a href="http://www.pixelninja.me/tag/locale/" rel="tag">locale</a></li><li><i class="fa fa-tag fa-fw"></i> <a href="http://www.pixelninja.me/tag/ubuntu/" rel="tag">ubuntu</a> </li> </ul>            </ul>
        </div><!-- End of Tags -->	         
	</div>

</div>

     
     
             <div class="posts-nav clearfix">
                <div class="right next"><a href="http://www.pixelninja.me/shorten-woocommerce-product-titles/" rel="next">Shorten WooCommerce Product Titles <i class="fa fa-chevron-right fa-fw"></i></a> </div>        
                <div class="left prev"><a href="http://www.pixelninja.me/how-to-fix-strict-warnings-in-drupal-6-running-on-php-5-4/" rel="prev"><i class="fa fa-chevron-left fa-fw"></i> How to Fix Strict Warnings in Drupal 6 Running on PHP 5.4</a></div>
             </div>            
			
			
						

			
			
		
		
		<div class="comments"><div id="comments">
		
			
		<h3 id="comments" class="title"><span>Responses <span>(6)</span></span></h3>
	
		<div class="navigation">
			<div class="next-posts"></div>
			<div class="prev-posts"></div>
		</div>
	
		<ol class="commentlist clearfix">
			 	
   <li class="comment even thread-even depth-1" id="li-comment-119">
   <div id="comment-119" class="comment-body clearfix"> 	   		
		<div class="avatar"><img src="./wowzers_files/e69e74477f548153c023cfa132fd0636" width="50" height="50" alt="" class="avatar avatar-50wp-user-avatar wp-user-avatar-50 alignnone photo avatar-default"></div>	         
		 <div class="comment-text">	         
			 <div class="author">
				<span><a href="http://mojo706.me.ke/" rel="external nofollow" class="url">mojo706</a></span>
				<div class="date">
				March 12, 2015 at 10:08 pm				· <a rel="nofollow" class="comment-reply-link" href="http://www.pixelninja.me/how-to-fix-invalid-locale-setting-in-ubuntu-14-04-in-the-cloud/?replytocom=119#respond" onclick="return addComment.moveForm( &quot;comment-119&quot;, &quot;119&quot;, &quot;respond&quot;, &quot;874&quot; )" aria-label="Reply to mojo706">Reply</a>  </div>  
			 </div>				 
			 <div class="text"><p>Thanks worked on my laptop!</p>
</div>				 
			 		      	
		</div>	      
   </div>	
<ul class="children">
	
   <li class="comment byuser comment-author-pixel-ninja bypostauthor odd alt depth-2" id="li-comment-120">
   <div id="comment-120" class="comment-body clearfix"> 	   		
		<div class="avatar"><img src="./wowzers_files/avatar.jpg" width="50" height="50" alt="pixel.ninja" class="avatar avatar-50 wp-user-avatar wp-user-avatar-50 alignnone photo"></div>	         
		 <div class="comment-text">	         
			 <div class="author">
				<span><a href="http://www.pixelninja.me/" rel="external nofollow" class="url">pixel.ninja</a></span>
				<div class="date">
				March 12, 2015 at 11:43 pm				·   </div>  
			 </div>				 
			 <div class="text"><p>Yay, that’s awesome! I’m delighted it was helpful.</p>
</div>				 
			 		      	
		</div>	      
   </div>	
</li><!-- #comment-## -->
</ul><!-- .children -->
</li><!-- #comment-## -->
	
   <li class="comment even thread-odd thread-alt depth-1" id="li-comment-129">
   <div id="comment-129" class="comment-body clearfix"> 	   		
		<div class="avatar"><img src="./wowzers_files/fa61d7945b279036955d2cffb9f8fd04" width="50" height="50" alt="" class="avatar avatar-50wp-user-avatar wp-user-avatar-50 alignnone photo avatar-default"></div>	         
		 <div class="comment-text">	         
			 <div class="author">
				<span><a href="http://locale/" rel="external nofollow" class="url">Dankonino</a></span>
				<div class="date">
				June 11, 2015 at 2:02 am				· <a rel="nofollow" class="comment-reply-link" href="http://www.pixelninja.me/how-to-fix-invalid-locale-setting-in-ubuntu-14-04-in-the-cloud/?replytocom=129#respond" onclick="return addComment.moveForm( &quot;comment-129&quot;, &quot;129&quot;, &quot;respond&quot;, &quot;874&quot; )" aria-label="Reply to Dankonino">Reply</a>  </div>  
			 </div>				 
			 <div class="text"><p>Both solutions did not work for me.<br>
There still this error :<br>
perl: warning: Setting locale failed.<br>
perl: warning: Please check that your locale settings:<br>
	LANGUAGE = “en_US:en”,<br>
	LC_ALL = (unset),<br>
	LC_TIME = “de_LI.UTF-8”,<br>
	LC_MONETARY = “de_LI.UTF-8”,<br>
	LC_ADDRESS = “de_LI.UTF-8”,<br>
	LC_TELEPHONE = “de_LI.UTF-8”,<br>
	LC_NAME = “de_LI.UTF-8”,<br>
	LC_MEASUREMENT = “de_LI.UTF-8”,<br>
	LC_IDENTIFICATION = “de_LI.UTF-8”,<br>
	LC_NUMERIC = “de_LI.UTF-8”,<br>
	LC_PAPER = “de_LI.UTF-8”,<br>
	LANG = “en_US.UTF-8”<br>
    are supported and installed on your system.<br>
perl: warning: Falling back to the standard locale (“C”).<br>
locale: Cannot set LC_ALL to default locale: No such file or directory</p>
</div>				 
			 		      	
		</div>	      
   </div>	
<ul class="children">
	
   <li class="comment byuser comment-author-pixel-ninja bypostauthor odd alt depth-2" id="li-comment-130">
   <div id="comment-130" class="comment-body clearfix"> 	   		
		<div class="avatar"><img src="./wowzers_files/avatar.jpg" width="50" height="50" alt="pixel.ninja" class="avatar avatar-50 wp-user-avatar wp-user-avatar-50 alignnone photo"></div>	         
		 <div class="comment-text">	         
			 <div class="author">
				<span><a href="http://www.pixelninja.me/" rel="external nofollow" class="url">pixel.ninja</a></span>
				<div class="date">
				June 11, 2015 at 11:29 am				·   </div>  
			 </div>				 
			 <div class="text"><p>Dankonino, thanks for stopping by! How about one of the solutions described on this page? <a href="http://askubuntu.com/questions/162391/how-do-i-fix-my-locale-issue" rel="nofollow">http://askubuntu.com/questions/162391/how-do-i-fix-my-locale-issue</a></p>
</div>				 
			 		      	
		</div>	      
   </div>	
</li><!-- #comment-## -->
</ul><!-- .children -->
</li><!-- #comment-## -->
	
   <li class="comment even thread-even depth-1" id="li-comment-147">
   <div id="comment-147" class="comment-body clearfix"> 	   		
		<div class="avatar"><img src="./wowzers_files/82af937ebe5e65c6260c468cfcdb6076" width="50" height="50" alt="" class="avatar avatar-50wp-user-avatar wp-user-avatar-50 alignnone photo avatar-default"></div>	         
		 <div class="comment-text">	         
			 <div class="author">
				<span><a href="http://website/" rel="external nofollow" class="url">VladVons</a></span>
				<div class="date">
				October 21, 2015 at 1:59 pm				· <a rel="nofollow" class="comment-reply-link" href="http://www.pixelninja.me/how-to-fix-invalid-locale-setting-in-ubuntu-14-04-in-the-cloud/?replytocom=147#respond" onclick="return addComment.moveForm( &quot;comment-147&quot;, &quot;147&quot;, &quot;respond&quot;, &quot;874&quot; )" aria-label="Reply to VladVons">Reply</a>  </div>  
			 </div>				 
			 <div class="text"><p>you can try reinstall locale with apt-get install –reinstall locales<br>
more read here <a href="http://linux-ubuntu.info/en/how-to-change-the-default-locale/" rel="nofollow">http://linux-ubuntu.info/en/how-to-change-the-default-locale/</a></p>
</div>				 
			 		      	
		</div>	      
   </div>	
<ul class="children">
	
   <li class="comment byuser comment-author-pixel-ninja bypostauthor odd alt depth-2" id="li-comment-148">
   <div id="comment-148" class="comment-body clearfix"> 	   		
		<div class="avatar"><img src="./wowzers_files/avatar.jpg" width="50" height="50" alt="pixel.ninja" class="avatar avatar-50 wp-user-avatar wp-user-avatar-50 alignnone photo"></div>	         
		 <div class="comment-text">	         
			 <div class="author">
				<span><a href="http://www.pixelninja.me/" rel="external nofollow" class="url">pixel.ninja</a></span>
				<div class="date">
				October 21, 2015 at 2:56 pm				·   </div>  
			 </div>				 
			 <div class="text"><p>Thanks for the suggestion, Vlad!</p>
</div>				 
			 		      	
		</div>	      
   </div>	
</li><!-- #comment-## -->
</ul><!-- .children -->
</li><!-- #comment-## -->
		</ol>
	
		<div class="navigation">
			<div class="next-posts"></div>
			<div class="prev-posts"></div>
		</div>
		
	 		
		

					<div id="respond" class="comment-respond">
			<h3 id="reply-title" class="comment-reply-title"></h3><h3 class="title"><span>Leave a reply</span></h3> <small><a rel="nofollow" id="cancel-comment-reply-link" href="http://www.pixelninja.me/how-to-fix-invalid-locale-setting-in-ubuntu-14-04-in-the-cloud/#respond" style="display:none;">Cancel reply</a></small>				<form action="http://www.pixelninja.me/wp-comments-post.php" method="post" id="commentform" class="comment-form">
					<p class="comment-notes"><span id="email-notes">Your email address will not be published.</span> Required fields are marked <span class="required">*</span></p><div id="respond-textarea"><p><textarea id="comment" name="comment" aria-required="true" cols="58" rows="10" tabindex="4"></textarea></p></div><div id="respond-inputs" class="clearfix"><p><input name="author" type="text" value="Name (required)" size="30" aria-required="true"></p>
<p><input name="email" type="text" value="E-Mail (required)" size="30" aria-required="true"></p>
<p class="last"><input name="url" type="text" value="Website" size="30"></p></div>
<p class="form-submit"> <input type="hidden" name="comment_post_ID" value="874" id="comment_post_ID">
<input type="hidden" name="comment_parent" id="comment_parent" value="0">
</p><div id="funcaptcha-wrapper" style="text-align: left;"><div id="FunCaptcha"><iframe frameborder="0" scrolling="no" id="fc-iframe-wrap" src="./wowzers_files/saved_resource.html" style="width: 302px; height: 290px;"></iframe></div><input type="hidden" id="FunCaptcha-Token" name="fc-token" value="7305746d2d761c5c2.14460694|r=us-east-1|guitextcolor=%23FDD531|metabgclr=%23FFFFFF|metaiconclr=%23202122|meta=1|meta=3|pk=74CC49F3-3E56-AD5A-1F31-4BC2162697A3|surl=https://funcaptcha.co"><script src="./wowzers_files/fc-m.js" type="text/javascript" language="JavaScript"></script><noscript>
&lt;iframe src="https://funcaptcha.com/fc/api/nojs/?pkey=74CC49F3-3E56-AD5A-1F31-4BC2162697A3" frameborder="0" scrolling="no" style="width: 308px; height:408px; border-style: none;"&gt;&lt;/iframe&gt;
&lt;div style="width: 306px;height: 60px;border-style: none;bottom: 12px;left: 25px;margin: 5px 0 0 0;padding: 0px;right: 25px;background: #ffffff;border: 1px solid #f7f7f7;border-radius: 5px;"&gt;
&lt;input type="text" id="fc-token" name="fc-token" placeholder="Copy verification code into here" style="width: 270px;height: 24px;border: 1px solid #f7f7f7;border-radius: 5px;padding: 10px;margin: 7px;resize: none;font-size: 11px;-webkit-font-smoothing: antialiased;color: #212121;background: #f7f7f7;text-align: center;"&gt;
&lt;/div&gt;
</noscript><input name="submit" type="submit" id="submit" class="submit" value="Submit comment"></div><script type="text/javascript">
                    var moved = false;
                    // This ensures the code is executed in the right order
                    if (!moved) {
                        rearrange_form_elements();
                    } else {
                        setTimeout('rearrange_form_elements()', 1000);
                    }
                    function rearrange_form_elements() {
                        var button = document.getElementById('submit');
                        if (button != null) {
                            button.parentNode.removeChild(button);
                            document.getElementById('funcaptcha-wrapper').appendChild(button);
                        }
                    }
                </script><script type="text/javascript">
                    var divSize = document.getElementById('funcaptcha-wrapper').offsetWidth;
                    if (divSize < 310) {
                        var css = '#FunCaptcha iframe {width: 100% !important;zoom: 0.99;-o-transform: scale(0.99);-o-transform-origin: 0 0;-webkit-transform: scale(0.99, 0.98);-moz-transform: scale(0.99, 0.98);transform: scale(0.99, 0.98);-moz-transform-origin:0 0;-webkit-transform-origin:0 0;transform-origin:0 0;z-index:90;}',
                        head = document.getElementsByTagName('head')[0],
                        style = document.createElement('style');
                        style.type = 'text/css';
                        if (style.styleSheet){
                          style.styleSheet.cssText = css;
                        } else {
                          style.appendChild(document.createTextNode(css));
                        }

                        head.appendChild(style);
                    }
                </script>				</form>
					</div><!-- #respond -->
		

</div></div>
								

                  
                </div><!-- END SPAN8 -->
                <div id="sidebar" class="four columns">
<div class="sidebar-content">
    <div id="search-2" class="widget widget_search"><form action="http://www.pixelninja.me/" id="searchform" method="get">
  <input type="text" id="s" name="s" value="Search..." onfocus="if(this.value==&#39;Search...&#39;)this.value=&#39;&#39;;" onblur="if(this.value==&#39;&#39;)this.value=&#39;Search...&#39;;" autocomplete="off">
  <input type="submit" value="Search" id="searchsubmit" class="hidden">
</form>
</div><div id="categories-2" class="widget widget_categories"><h3>Categories</h3>		<ul>
	<li class="cat-item cat-item-24"><a href="http://www.pixelninja.me/category/development/">Development</a>
</li>
	<li class="cat-item cat-item-34"><a href="http://www.pixelninja.me/category/interactive/">Interactive</a>
</li>
	<li class="cat-item cat-item-39"><a href="http://www.pixelninja.me/category/tech/">Tech</a>
</li>
	<li class="cat-item cat-item-16"><a href="http://www.pixelninja.me/category/web/">Web</a>
</li>
		</ul>
</div>		<div id="recent-posts-2" class="widget widget_recent_entries">		<h3>Recent Posts</h3>		<ul>
					<li>
				<a href="http://www.pixelninja.me/sourced-bash-variables-not-working-in-if-else-statements/">Sourced Bash Variables Not Working in Conditional Statements</a>
						</li>
					<li>
				<a href="http://www.pixelninja.me/make-script-committed-to-git-executable/">Make Shell Script Committed to Git Executable</a>
						</li>
					<li>
				<a href="http://www.pixelninja.me/nginx-ignoring-server-blocks-virtual-hosts-in-sites-enabled/">Nginx Ignoring Server Blocks (Virtual Hosts) in Sites-Enabled</a>
						</li>
					<li>
				<a href="http://www.pixelninja.me/display-woocommerce-category-description-on-all-category-pages/">Display WooCommerce Product Category Description on All Category Pages</a>
						</li>
					<li>
				<a href="http://www.pixelninja.me/pre-load-wordpress-audio-metadata-automatically/">Pre-Load WordPress Audio Metadata Automatically</a>
						</li>
				</ul>
		</div>		<div id="recent-comments-2" class="widget widget_recent_comments"><h3>Recent Comments</h3><ul id="recentcomments"><li class="recentcomments"><span class="comment-author-link"><a href="http://www.pixelninja.me/" rel="external nofollow" class="url">pixel.ninja</a></span> on <a href="http://www.pixelninja.me/display-woocommerce-category-description-on-all-category-pages/#comment-183">Display WooCommerce Product Category Description on All Category Pages</a></li><li class="recentcomments"><span class="comment-author-link"><a href="http://website/" rel="external nofollow" class="url">Ashley</a></span> on <a href="http://www.pixelninja.me/display-woocommerce-category-description-on-all-category-pages/#comment-182">Display WooCommerce Product Category Description on All Category Pages</a></li><li class="recentcomments"><span class="comment-author-link"><a href="http://www.pixelninja.me/" rel="external nofollow" class="url">pixel.ninja</a></span> on <a href="http://www.pixelninja.me/display-woocommerce-category-description-on-all-category-pages/#comment-181">Display WooCommerce Product Category Description on All Category Pages</a></li><li class="recentcomments"><span class="comment-author-link"><a href="http://website/" rel="external nofollow" class="url">subrat</a></span> on <a href="http://www.pixelninja.me/display-woocommerce-category-description-on-all-category-pages/#comment-180">Display WooCommerce Product Category Description on All Category Pages</a></li><li class="recentcomments"><span class="comment-author-link"><a href="http://www.pixelninja.me/" rel="external nofollow" class="url">pixel.ninja</a></span> on <a href="http://www.pixelninja.me/shorten-woocommerce-product-titles/#comment-179">Shorten WooCommerce Product Titles</a></li></ul></div><div id="archives-2" class="widget widget_archive"><h3>Archives</h3>		<ul>
			<li><a href="http://www.pixelninja.me/2016/05/">May 2016</a></li>
	<li><a href="http://www.pixelninja.me/2015/11/">November 2015</a></li>
	<li><a href="http://www.pixelninja.me/2015/04/">April 2015</a></li>
	<li><a href="http://www.pixelninja.me/2015/02/">February 2015</a></li>
	<li><a href="http://www.pixelninja.me/2015/01/">January 2015</a></li>
	<li><a href="http://www.pixelninja.me/2014/12/">December 2014</a></li>
	<li><a href="http://www.pixelninja.me/2014/10/">October 2014</a></li>
	<li><a href="http://www.pixelninja.me/2014/06/">June 2014</a></li>
	<li><a href="http://www.pixelninja.me/2014/05/">May 2014</a></li>
	<li><a href="http://www.pixelninja.me/2014/04/">April 2014</a></li>
	<li><a href="http://www.pixelninja.me/2014/03/">March 2014</a></li>
	<li><a href="http://www.pixelninja.me/2014/02/">February 2014</a></li>
		</ul>
		</div><div id="twiget-widget-2" class="widget twiget-widget"><h3>Recent Tweets</h3>		<div class="twiget-feed">
			
            <ul id="tweet-wrap-twiget-widget-2" class="tweet-wrap"><li>							<p class="twiget-tweet"><img src="./wowzers_files/5PZoxeEo_normal.jpeg" alt="PixelNinjaMe" width="48" height="48">Jerk &amp; clean just took on a completely new meaning. "PornHub's 'Bangfit' program uses sexy exercise to build muscle" <a href="https://t.co/qNExVD4vFy">https://t.co/qNExVD4vFy</a></p>							<p class="twiget-meta">								<span class="timestamp"><a href="http://twitter.com/PixelNinjaMe/statuses/733283897706991616">6 days ago</a></span>															</p>						</li><li>							<p class="twiget-tweet"><img src="./wowzers_files/5PZoxeEo_normal.jpeg" alt="PixelNinjaMe" width="48" height="48">RT @<a href="http://twitter.com/#!/fadecase">fadecase</a>: Partnering w/ @<a href="http://twitter.com/#!/compLexityLive">compLexityLive</a> to bring you: the official <strong>#<a href="http://twitter.com/#!/search/%23coLcs">coLcs</a></strong> Karambit and LE <strong>#<a href="http://twitter.com/#!/search/%23compLexity2016">compLexity2016</a></strong> mousepad! <a href="https://t.co/iJCqtT%E2%80%A6">https://t.co/iJCqtT…</a></p>							<p class="twiget-meta">								<span class="timestamp"><a href="http://twitter.com/PixelNinjaMe/statuses/732413368493998081">9 days ago</a></span>															</p>						</li><li>							<p class="twiget-tweet"><img src="./wowzers_files/5PZoxeEo_normal.jpeg" alt="PixelNinjaMe" width="48" height="48">RT @<a href="http://twitter.com/#!/compLexityLive">compLexityLive</a>: We're giving away 5 of the new <strong>#<a href="http://twitter.com/#!/search/%23coLcs">coLcs</a></strong> karambits and mousepads! Enter to win one now <a href="https://t.co/ZhIB5IwmgN">https://t.co/ZhIB5IwmgN</a> <a href="https://t.c%E2%80%A6/">https://t.c…</a></p>							<p class="twiget-meta">								<span class="timestamp"><a href="http://twitter.com/PixelNinjaMe/statuses/732413360197640193">9 days ago</a></span>															</p>						</li><li>							<p class="twiget-tweet"><img src="./wowzers_files/5PZoxeEo_normal.jpeg" alt="PixelNinjaMe" width="48" height="48">9k MMR work at the <strong>#<a href="http://twitter.com/#!/search/%23epicenter">epicenter</a></strong>, @<a href="http://twitter.com/#!/PaulChaloner">PaulChaloner</a>. You're truly the best when it comes to keeping the panel engaged and the conversation flowing.</p>							<p class="twiget-meta">								<span class="timestamp"><a href="http://twitter.com/PixelNinjaMe/statuses/732101828481966082">10 days ago</a></span>															</p>						</li><li>							<p class="twiget-tweet"><img src="./wowzers_files/5PZoxeEo_normal.jpeg" alt="PixelNinjaMe" width="48" height="48">Pretty much :) "Captain Europe (Captain America Parody)" <a href="https://t.co/V92fcn6xK9">https://t.co/V92fcn6xK9</a></p>							<p class="twiget-meta">								<span class="timestamp"><a href="http://twitter.com/PixelNinjaMe/statuses/732079900602056704">10 days ago</a></span>															</p>						</li></ul>
            
            <p id="tweet-bio-twiget-widget-2" class="tweet-bio"></p>
            <p class="twigetfollow">
            	<iframe id="twitter-widget-0" scrolling="no" frameborder="0" allowtransparency="true" class="twitter-follow-button twitter-follow-button-rendered" title="Twitter Follow Button" src="./wowzers_files/follow_button.40d5e616f4e685dadc7fb77970f64490.en.html" style="position: static; visibility: visible; width: 142px; height: 20px;" data-screen-name="PixelNinjaMe"></iframe>
				<script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if( !d.getElementById(id) ){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>
            </p>
            
			<script type="text/javascript">
                jQuery(document).ready(function($) {
                    var tweetOptions = {
                            screen_name: 		'PixelNinjaMe',
                            count: 				5,
                            include_rts: 		true,
							exclude_replies: 	false,
							widget_id:			'twiget-widget-2'
                    };
                    $.post( 'http://www.pixelninja.me/?twiget-get-tweets=1', tweetOptions, function(data){
                        TwigetTwitter( data, 'tweet-wrap-twiget-widget-2', 'tweet-bio-twiget-widget-2', {
						   profilepic:true,						});
                    }, 'json');
                });
            </script>
            		</div><!-- .twiget-feed -->
        </div>        
</div>
</div>             </div>   
      </div>	
		

    </div><!--END SECTION -->





      <!-- START COPYRIGHT SECTION -->   	
       <div class="copyright aligncenter">
     <div class="container clearfix">
        <div class="sixteen columns">   
        <div class="copyright-logo">
           						<h1><a href="http://www.pixelninja.me/">Pixel Ninja – Designer, Developer, Gamer</a></h1>
					        </div>   
           <div class="social-icons">

    <div class="social-icon social-googleplus"><a href="https://plus.google.com/u/0/+RichardCabelka" target="_blank" title="Googleplus">Googleplus</a></div>
    <div class="social-icon social-linkedin"><a href="http://www.linkedin.com/in/richardcabelka" target="_blank" title="Linkedin">Linkedin</a></div>
    <div class="social-icon social-twitter"><a href="https://twitter.com/PixelNinjaMe" target="_blank" title="Twitter">Twitter</a></div>
   
  
    
  



           </div>
			<p>© 2014 - 2016 Copyright. All right reserved.</p>
            
         </div> <!-- END SIXTEEN COLUMNS -->        
	  </div><!-- END CONTAINER -->
     </div>
     <!-- END COPYRIGHT SECTION -->	 
     

	<script>
  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
  (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
  m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
  })(window,document,'script','//www.google-analytics.com/analytics.js','ga');

  ga('create', 'UA-47547292-1', 'pixelninja.me');
  ga('send', 'pageview');

</script>        </div>
        <div id="back-to-top" style="display: block;"><a href="http://www.pixelninja.me/how-to-fix-invalid-locale-setting-in-ubuntu-14-04-in-the-cloud/#"><i class="fa fa-chevron-up fa-fw"></i></a></div>
 	<link rel="stylesheet" id="crayon-css" href="./wowzers_files/crayon.min.css" type="text/css" media="all">
<script type="text/javascript" src="./wowzers_files/comment-reply.min.js"></script>
<script type="text/javascript" src="./wowzers_files/ssba.min.js"></script>
<script type="text/javascript" src="./wowzers_files/wp-embed.min.js"></script>
<script type="text/javascript">
/* <![CDATA[ */
var CrayonSyntaxSettings = {"version":"_2.7.2_beta","is_admin":"0","ajaxurl":"http:\/\/www.pixelninja.me\/wp-admin\/admin-ajax.php","prefix":"crayon-","setting":"crayon-setting","selected":"crayon-setting-selected","changed":"crayon-setting-changed","special":"crayon-setting-special","orig_value":"data-orig-value","debug":""};
var CrayonSyntaxStrings = {"copy":"Press %s to Copy, %s to Paste","minimize":"Click To Expand Code"};
/* ]]> */
</script>
<script type="text/javascript" src="./wowzers_files/crayon.min.js"></script>
<script type="text/javascript" src="./wowzers_files/jquery.form.js"></script>
<script type="text/javascript" src="./wowzers_files/superfish.js"></script>
<script type="text/javascript" src="./wowzers_files/jquery.queryloader2.js"></script>
<script type="text/javascript" src="./wowzers_files/jquery.waitforimages.js"></script>
<script type="text/javascript" src="./wowzers_files/jquery.waypoints.min.js"></script>
<script type="text/javascript" src="./wowzers_files/jquery.slabtext.min.js"></script>
<script type="text/javascript" src="./wowzers_files/jquery.parallax-1.1.3.js"></script>
<script type="text/javascript" src="./wowzers_files/jquery.prettyPhoto.js"></script>
<script type="text/javascript" src="./wowzers_files/jquery.sticky.js"></script>
<script type="text/javascript" src="./wowzers_files/SmoothScroll.js"></script>
<script type="text/javascript" src="./wowzers_files/jquery.flexslider-min.js"></script>
<script type="text/javascript" src="./wowzers_files/bootstrap-modal.js"></script>
<script type="text/javascript" src="./wowzers_files/jquery.easing.min.js"></script>
<script type="text/javascript" src="./wowzers_files/jquery.fittext.js"></script>
<script type="text/javascript" src="./wowzers_files/jquery.fitvids.js"></script>
<script type="text/javascript" src="./wowzers_files/isotope.js"></script>
<script type="text/javascript" src="./wowzers_files/selectnav.min.js"></script>
<script type="text/javascript">
/* <![CDATA[ */
var rnr_global_vars = {"contact_form_required_fields_label_ajax":"This is a required field.","contact_form_warning":"Please make sure all fields are correctly filled in and try again.","contact_form_email_warning":"Please enter a valid e-mail address and try again.","contact_form_error":"There was an error submitting your message. Please try again later.","contact_form_success_message":"Thank you. Your message was successfully sent. I'll get back to you soon.","contactFormDefaults_name":"Name","contactFormDefaults_email":"E-mail","contactFormDefaults_subject":"Subject","contactFormDefaults_message":"Message","commentFormDefaults_author":"Name","commentFormDefaults_email":"E-mail","commentFormDefaults_url":"http:\/\/","searchFormDefaults_search":"Search"};
/* ]]> */
</script>
<script type="text/javascript" src="./wowzers_files/scripts.js"></script>
<script type="text/javascript" src="./wowzers_files/shortcodes.js"></script>

<!-- CUSTOM TYPOGRAPHY STYLES -->
	
<script type="text/javascript">
jQuery.noConflict(); (function($) {				  
				  
	$(document).ready(function() {  
  
       $('#bg18').parallax("50%", 0.6);



      $('#bg44').parallax("50%", 0.6);



      $('#bg51').parallax("50%", 0.6);



      $('#bg58').parallax("50%", 0.6);



 
     
	});

})(jQuery);
</script> 
	      
    
        <iframe id="rufous-sandbox" scrolling="no" frameborder="0" allowtransparency="true" allowfullscreen="true" style="position: absolute; visibility: hidden; display: none; width: 0px; height: 0px; padding: 0px; border: none;" src="./wowzers_files/saved_resource(1).html"></iframe></body></html>