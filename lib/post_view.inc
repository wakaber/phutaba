<if !$parent>
	<article class="thread_OP" id="<var $num>">
	<header class="thread_head">
</if>

<if $parent>
	<article class="thread_reply" id="<var $num>">
	<div class="doubledash">
	<a href="<var get_reply_link($parent,0)>#<var $num>">&gt;&gt;</a>
	</div>

	<section class="post<if $single> post_new</if>">
	<section class="post_head">
</if>

	<if ENABLE_HIDE_THREADS && !$thread && !$parent>
		<span class="togglethread">
		<img src="/img/icons/hide.png" title="<var sprintf S_HIDE, $num>" alt="Hide" onclick="hideThread('<var $num>', '<const BOARD_IDENT>', $j);" />
		</span>
	</if>

	<label>
		<input type="checkbox" name="delete" value="<var $num>" />
		<span class="subject"><var $subject></span>
        <span class="postername"><var $name><if $trip><span class="tripcode"><var $trip></span></if></span>
		<if $adminpost><span class="teampost">## Team ##</span></if>
		<span class="date"><var encode_entities(get_date($timestamp))></span>
	</label>

	<if SSL_ICON && $secure>
		<span class="ssl" onmouseover="Tip('<var $secure>')" onmouseout="UnTip()"><img src="<var SSL_ICON>" alt="SSL" /></span>
	</if>

	<span class="reflink">
                <if !$parent>
                        <a href="<var get_reply_link($num,0)>#i<var $num>">Nr. <var $num></a>
                </if>			
                <if $parent>
                        <a href="<var get_reply_link($parent,0)>#i<var $num>">Nr. <var $num></a>
                </if>
	</span>

	<if !$parent>
		<if !$sticky_isnull><span class="sticky"><img src="/img/icons/pin.png" onmouseover="Tip('<var S_STICKYTITLE>')" onmouseout="UnTip()" alt="Pin" /></span></if>
		<if $locked><span class="locked"><img src="/img/icons/locked.png" onmouseover="Tip('<var S_LOCKEDTITLE>')" onmouseout="UnTip()" alt="Lock" /></span></if>
		<if !$autosage><if $email><span class="sage"><const S_SAGE></span></if></if>
		<if $sticky_isnull><if $autosage><span class="sage">Systemkontra</span></if></if>
	</if>

	<if $parent>
		<if $email><span class="sage"><const S_SAGE></span></if>
	</if>

	<if !$parent && !$thread>	
		<span class="replylink">[<a href="<var get_reply_link($num,0)>"><const S_REPLY></a>]</span>
	</if>

	<if $isAdmin>
		<if !$adminpost>
		<div style="display: none; min-width: 250px;" id="postinfo_<var $num>">
			<var get_post_info($location)>
		</div>
		<span onmouseover="TagToTip('postinfo_<var $num>', TITLE, '<const S_POSTINFO>', DELAY, 0, CLICKSTICKY, true)" onmouseout="UnTip()">[<var dec_to_dot($ip)>]</span>
		</if>
		<if !$parent>	
			<if $sticky_isnull>
				<span class="sticky" onmouseover="Tip('<const S_MPSTICKY>')" onmouseout="UnTip()"><a href="<var $self>?task=sticky&amp;threadid=<var $num>"><img src="/img/icons/sticky.png"></a></span>
			</if>

			<if !$sticky_isnull>
				<span class="unsticky" onmouseover="Tip('<const S_MPUNSTICKY>')" onmouseout="UnTip()"><a href="<var $self>?task=sticky&amp;threadid=<var $num>"><img src="/img/icons/unsticky.png"></a></span>
			</if>
			
			<if !$locked>
				<span class="lock" onmouseover="Tip('<const S_MPLOCK>')" onmouseout="UnTip()"><a href="<var $self>?task=lock&amp;threadid=<var $num>"><img src="/img/icons/lock.png"></a></span>
			</if>

			<if $locked>
				<span class="unlock" onmouseover="Tip('<const S_MPUNLOCK>')" onmouseout="UnTip()"><a href="<var $self>?task=lock&amp;threadid=<var $num>"><img src="/img/icons/unlock.png"></a></span>
			</if>
		
			<if !$autosage>
				<span class="lock" onmouseover="Tip('<const S_MPSETSAGE>')" onmouseout="UnTip()"><a href="<var $self>?task=kontra&amp;threadid=<var $num>"><img src="/img/icons/sage.png"></a></span>
			</if>

			<if $autosage>
				<span class="autosage" onmouseover="Tip('<const S_MPUNSETSAGE>')" onmouseout="UnTip()"><a href="<var $self>?task=kontra&amp;threadid=<var $num>"><img src="/img/icons/unsage.png"></a></span>
			</if>
			
		</if>
		<if !$adminpost>
		<span class="ban"         onmouseover="Tip('<const S_MPBAN>')"       onmouseout="UnTip()"><a onclick="do_ban('<var dec_to_dot($ip)>', <var $num>, '<const BOARD_IDENT>')"><img src="/img/icons/ban.png"></a></span>
		<span class="deleteall"   onmouseover="Tip('<const S_MPDELETEALL>')" onmouseout="UnTip()"><a href="<var $self>?task=deleteall&amp;ip=<var $ip>"><img src="/img/icons/delete_all.png"></a></span>
		</if>
		<span class="delete_file" onmouseover="Tip('<const S_MPDELFILE>')"   onmouseout="UnTip()"><a href="<var $self>?task=delete&amp;delete=<var $num>&amp;fileonly=on"><img src="/img/icons/delete_file.png"></a></span>
		<span class="delete_post" onmouseover="Tip('<const S_MPDELETE>')"    onmouseout="UnTip()"><a href="<var $self>?task=delete&amp;delete=<var $num>"><img src="/img/icons/delete.png"></a></span>
	</if>

<if $parent>
	</section>
</if>

<if !$parent>
	</header>
	<section class="post">
</if>

<section class="post_body">

<loop $files>

<if $thumbnail><section class="file"></if>
<if !$thumbnail><section class="file filebg"></if>
	<div style="display: none; min-width: 250px;" id="imageinfo_<var md5_hex($image)>">
		<strong>Dateiname:</strong> <var $uploadname><br />
		<hr />
		<var get_pretty_html($info_all, "\n\t\t")>
	</div>
	<div class="filename"><const S_PICNAME><a target="_blank" title="<var $uploadname>" href="<var expand_image_filename($image)>/<var get_urlstring($uploadname)>"><var $displayname></a></div>
	<div class="filesize"><var get_displaysize($size, DECIMAL_MARK)><if $width && $height>, <var $width>&nbsp;&times;&nbsp;<var $height></if><if $info>, <var $info></if></div>
	<if $thumbnail>
		<div class="filelink">
		<a target="_blank" href="<var expand_image_filename($image)>">
			<img onmouseover="TagToTip('imageinfo_<var md5_hex($image)>', TITLE, '<const S_FILEINFO>', WIDTH, 300)" onmouseout="UnTip()"
				<if get_extension($image) eq 'JPG' or get_extension($image) eq 'PNG' or get_extension($image) eq 'GIF'>onclick="return expand_image(event, <var $tn_width>, <var $tn_height>, <var $width>, <var $height>, '<var expand_filename($thumbnail)>', '<var expand_image_filename($image)>')"</if>
				src="<var expand_filename($thumbnail)>" width="<var $tn_width>" height="<var $tn_height>" alt="<var $size>" />
		</a>
		</div>
	</if>
	<if !$thumbnail>
		<if !$size>
			<div class="filedeleted"><const S_FILEDELETED></div>
		</if>
		<if $size>
			<if DELETED_THUMBNAIL>
				<a target="_blank" href="<var expand_image_filename(DELETED_IMAGE)>">
					<img src="<var expand_filename(DELETED_THUMBNAIL)>" width="<var $tn_width>" height="<var $tn_height>" alt="" />
				</a>
			</if>
			<if !DELETED_THUMBNAIL>
				<div class="filetype">
					<a onmouseover="TagToTip('imageinfo_<var md5_hex($image)>', TITLE, '<const S_FILEINFO>', WIDTH, 300)" onmouseout="UnTip()" target="_blank" href="<var expand_image_filename($image)>">
						<var get_extension($uploadname)>
					</a>
				</div>
			</if>
		</if>		
	</if>
</section>

</loop>

	<section class="text">
		<if $abbrev>
			<div style="display: none;" id="posttext_full_<var $num>">
				<var $comment_full>
			</div>
		</if>

		<div id="posttext_<var $num>">
			<var $comment>
			<if $abbrev>
				<p class="tldr">
					[<a href="<var get_reply_link($num,$parent)>" onclick="return expand_post('<var $num>')"><var $abbrev></a>]
				</p>
			</if>
		</div>
		<if $banned><const S_BANNED></if>
	</section>

</section>
</section>
</article>

<if !$parent>
	<if $omitmsg>
		<aside class="omittedposts">
			<var $omitmsg>
		</aside>
	</if>
</if>