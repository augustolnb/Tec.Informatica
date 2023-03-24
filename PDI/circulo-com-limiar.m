pkg load image-acquisition;
MSG="CÍRCULO ENCONTRADO";
filtro = fspecial("sobel", 5, 1);

limiar = 0.020;

device = imaqhwinfo.device;
obj = videoinput("v4l2", device);
set(obj, "VideoResolution", [352 288]);
preview(obj);
start(obj);
snapshot_inicial = getsnapshot(obj);
snapshot_inicial = rgb2gray(snapshot_inicial);
snapshot_inicial = uint8(filter2(filtro, snapshot_inicial));
soma_snapshot = mean2(snapshot_inicial);
"Snapshot capturado"
preview(obj);
start(obj);
while(true)
	sleep(1)
	img = getsnapshot(obj);
	img_pb = rgb2gray(img);
	img_pb = uint8(filter2(filtro, img_pb));
	soma_img = mean2(img_pb);
	diferenca = abs(soma_snapshot - soma_img);
	diferenca
	imshow(img_pb);
	if(diferenca <= limiar)
		MSG
		stop(obj);
	    break
	endif
endwhile