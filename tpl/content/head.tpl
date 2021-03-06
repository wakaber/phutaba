<!DOCTYPE html> 
<html lang="en"> 

<head>
	<meta charset="utf-8" />
	<meta name="viewport" content="width=device-width, initial-scale=1" />
	<title>02ch <if %title>&raquo; <var %title></if></title>
	<link rel="stylesheet" type="text/css" href="/static/css/phutaba.css" />
	<link rel="shortcut icon" href="/img/favicon.ico" />
	<link rel="alternate stylesheet" type="text/css" href="/static/css/photon.css" title="Photon" />
	<link rel="alternate stylesheet" type="text/css" href="/static/css/futaba.css" title="Futaba" />
	<link rel="alternate stylesheet" type="text/css" href="/static/css/neutron.css" title="Neutron" />
	<link rel="alternate stylesheet" type="text/css" href="/static/css/kaiserchan.css" title="Kaiserchan" />
    <script type="text/javascript" src="https://www.google.com/jsapi"></script>
	<script type="text/javascript" src="/static/vendor/jquery-1.11.3.min.js"></script>
	<script type="text/javascript">var style_cookie="wakastyle";</script>
	<script type="text/javascript" src="/static/js/localstorage.js"></script>
	<script type="text/javascript" src="/static/js/wakaba3.js"></script>
</head>

<body>
<div class="content">

<nav>
	<ul class="menu">
<include tpl/nav_boards.html>
	</ul>

	<ul class="menu right">
<include tpl/nav_pages.html>
	</ul>
</nav>

<header>
	<div class="header">
		<div class="banner">
		<if !$ismain>
			<a href="/">
				<img src="/banner.pl" alt="02ch" />
			</a>
		</if>
		</div>
		<div class="boardname"><var %title></div>
	</div>
</header>

<hr />
