#!/usr/bin/lua
-- cli_scan.lua

local socket = require('socket');

host = 'localhost';
port = 5000;

cli = socket.connect(host, port);

os.execute("clear");

io.write("\n############################################");
io.write("\n###           Scan de redes Wifi         ###");
io.write("\n############################################");
io.write("\n### -> Quantos ciclos deseja realizar?   ###");
io.write("\n### * Cada ciclo faz 10 scans            ###");
io.write("\n############################################\n\n--> ");

quant = tonumber(io.read());
qtd = tostring(quant);
cli:send(qtd.."\n");

cont = 0

arq = io.open("z2.txt", "w");

io.write("\t\tScaneando...\nPor favor aguarde o processo terminar\n");

while true do
	dados = tostring(cli:receive());

	if not dados then
		break;
	end

	arq:write(dados.."\n");

	if string.match(dados, 'Terminou') ~= nil then
		cont = cont + 1;
		io.write("\n\tFim do "..cont.." ciclo\n");
		arq:write("\n***************Fim do Ciclo***************\n\n\n");
	end

	if tonumber(cont) == tonumber(quant) then
		io.write("\nServidor online\n");
		break;
	end
end

io.close(arq);
--io.close(cli);
--arq:close();
cli:close();

arq = io.open("z2.txt", "r");
ptr = io.open("qtd.txt", "w");

for i in arq:lines() do

	if string.match(i, 'Terminou_1') == nil then
		ptr:write(i.."\n");
	else
		break;
	end
end

scan = io.open("scan.txt", "w");
io.close(ptr);
ptr = io.open("qtd.txt", "r");

for i in ptr:lines() do
	if string.match(i, 'Numero de Scans: 2') == nil then
		scan:write(i.."\n");
	else
		break;
	end
end

io.write("\nFim do programa\n");
