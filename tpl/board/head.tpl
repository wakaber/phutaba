<include %TMPLDIR%/normal_head.tpl>
<if $admin>
	[<a href="<var Wakaba::expand_filename(Wakaba::get_board_path())>"><var $$locale{S_MANAPANEL}></a>]
	[<a href="<var %self>?task=mpanel&amp;section=<var $$cfg{SELFPATH}>"><var $$locale{S_MANATOOLS}></a>]
	[<a href="<var %self>?task=bans&amp;section=<var $$cfg{SELFPATH}>"><var $$locale{S_MANABANS}></a>]
	[<a href="<var %self>?task=orphans&amp;section=<var $$cfg{SELFPATH}>"><var $$locale{S_MANAORPH}></a>]
	<if $modclass eq "admin">
	[<a href="<var %self>?task=postbackups&amp;section=<var $$cfg{SELFPATH}>"><var $$locale{S_MANABACKS}></a>]
	[<a href="<var %self>?task=viewlog&amp;section=<var $$cfg{SELFPATH}>"><var $$locale{S_MANALOG}></a>]
	</if>
	[<a href="<var %self>?task=logout&amp;section=<var $$cfg{SELFPATH}>"><var $$locale{S_MANALOGOUT}></a>]
	<div class="passvalid"><var $$locale{S_MANAMODE}></div>
</if>
