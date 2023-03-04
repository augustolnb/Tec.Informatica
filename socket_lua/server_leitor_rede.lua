#!/usr/bin/lua
-- serv_scan.lua

local socket = require('socket');

host = "localhost";
port = 5000;

while true do

	os.execute("clear");

	local servidor = socket.bind(host, port);
	io.write("Aguardando conexão...\n");
	cnx = servidor:accept();
	io.write("Conectado\n");

	qtd = cnx:receive();

	quant = tonumber(qtd);

	l = 0;
	p = 1;

	while l < quant do
		w = 1;
		control = "---------------------------------------------------------------";
		Num = "\t\t\t\tNumero de Scans: ";
		c = 0;

		while w < 10 do
			os.execute("rm ifc.txt 2>error_rm");
			os.execute("iwlist wlan0 scan > ifc.txt");

			arq = io.open("ifc.txt", "r");

			b = 1;

			if c == 0 then
				c = 1;
			else if c == 1 then
				w = w + 1;
				end
			end

			s = tostring(w);

			cnx:send(control.."\n"..Num..s.."\n"..control.."\n");


			for i in arq:lines() do
				if string.match(i, 'Quality') ~= nil then
					if b > 1 then
						cnx:send("\n");
					end

					cnx:send("\n\t\tQualidade da rede "..b.."\n");
					cnx:send(i.."\n");

				else if string.match(i, 'ESSID') ~= nil then
					cnx:send("\n\t\tRede "..b.."\n");
					cnx:send(i.."\n");
					b = b + 1;
					end
				end
			end

			io.write(w.."° scan enviado".."\n");

			if w == 10 then
				if p == 1 then
					m = tostring(tonumber(b)-1);
					cnx:send("\n\tTerminou_1 -> "..m.." redes foram encontradas".."\n");
					p = p + 1;

				else if p ~= 1 then
					m = tostring(tonumber(b)-1);
					cnx:send("\n\tTerminou ->"..m.." redes foram encontradas".."\n");
					end
				end
			end

			arq:close();

		end
	
		io.write("\n\tFim de um ciclo\n");
		l = l + 1;
	end

	cnx:close();
	io.write("Fim do programa\n\n");
	servidor:close();
end
