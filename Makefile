stage0.bin: stage0.asm
	nasm -f bin -o stage0.bin stage0.asm

boot.img: stage0.asm
	nasm -f bin -o boot.img stage0.asm

boot: boot.img
	qemu-system-i386 -drive format=raw,file=boot.img

.PHONY: boot
