#!/usr/bin/env python
# -*- coding:utf-8 -*-
import socket
import os, sys

host = raw_input("Digite o IP: ")
port = raw_input("Digite a porta <default=5555>: ")

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # Socket tcp
sock.connect((host, port))

print "\n\nDigite 'x' para sair.\n"

comand = 'm'

while comand != 'x' or comand != 'X':
	comand = raw_input("Comando: ")
	comand = comand.lower()
	sock.send(comand)

comand = 'x'
sock.send(comand)

sock.close()



