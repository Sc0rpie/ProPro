	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 0
	.globl	_saveToFile                     ; -- Begin function saveToFile
	.p2align	2
_saveToFile:                            ; @saveToFile
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	x1, [x29, #-16]
	sub	x8, x29, #20
	str	x8, [sp]                        ; 8-byte Folded Spill
	stur	w2, [x29, #-20]
	ldur	x0, [x29, #-8]
	adrp	x1, l_.str@PAGE
	add	x1, x1, l_.str@PAGEOFF
	bl	_fopen
	mov	x8, x0
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	str	x8, [sp, #16]
	ldr	x3, [sp, #16]
	mov	x1, #4
	mov	x2, #1
	bl	_fwrite
	str	wzr, [sp, #12]
	b	LBB0_1
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #12]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.ge	LBB0_4
	b	LBB0_2
LBB0_2:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldur	x8, [x29, #-16]
	ldrsw	x9, [sp, #12]
	add	x0, x8, x9, lsl #2
	ldr	x3, [sp, #16]
	mov	x1, #4
	mov	x2, #1
	bl	_fwrite
	b	LBB0_3
LBB0_3:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	b	LBB0_1
LBB0_4:
	adrp	x9, _saveCount@GOTPAGE
	ldr	x9, [x9, _saveCount@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	ldr	x0, [sp, #16]
	bl	_fclose
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_loadFromFile                   ; -- Begin function loadFromFile
	.p2align	2
_loadFromFile:                          ; @loadFromFile
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-16]
	sub	x8, x29, #20
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	stur	w1, [x29, #-20]
	ldur	x0, [x29, #-16]
	adrp	x1, l_.str.1@PAGE
	add	x1, x1, l_.str.1@PAGEOFF
	bl	_fopen
	mov	x8, x0
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	str	x8, [sp, #32]
	ldr	x3, [sp, #32]
	mov	x1, #4
	mov	x2, #1
	bl	_fread
	subs	x8, x0, #1
	b.eq	LBB1_2
	b	LBB1_1
LBB1_1:
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-8]
	b	LBB1_7
LBB1_2:
	ldursw	x9, [x29, #-20]
	mov	x8, #4
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	mul	x0, x8, x9
	bl	_malloc
	ldr	x1, [sp, #8]                    ; 8-byte Folded Reload
	str	x0, [sp, #24]
	ldr	x0, [sp, #24]
	ldursw	x2, [x29, #-20]
	ldr	x3, [sp, #32]
	bl	_fread
	ldursw	x8, [x29, #-20]
	subs	x8, x0, x8
	b.eq	LBB1_4
	b	LBB1_3
LBB1_3:
	ldr	x0, [sp, #24]
	bl	_free
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-8]
	b	LBB1_7
LBB1_4:
	ldr	x0, [sp, #32]
	bl	_fclose
	adds	w8, w0, #1
	b.ne	LBB1_6
	b	LBB1_5
LBB1_5:
	ldr	x0, [sp, #24]
	bl	_free
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-8]
	b	LBB1_7
LBB1_6:
	adrp	x9, _loadCount@GOTPAGE
	ldr	x9, [x9, _loadCount@GOTPAGEOFF]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	ldr	x8, [sp, #24]
	stur	x8, [x29, #-8]
	b	LBB1_7
LBB1_7:
	ldur	x0, [x29, #-8]
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"wb"

	.comm	_saveCount,4,2                  ; @saveCount
l_.str.1:                               ; @.str.1
	.asciz	"rb"

	.comm	_loadCount,4,2                  ; @loadCount
.subsections_via_symbols
