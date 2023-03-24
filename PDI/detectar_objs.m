pkg load image-acquisition;
MSG="CENA INICIAL";
MSG2="OBJETO ENCONTRADO NA CENA";

sobel_h = [1 2 1;0 0 0;-1 -2 -1];
sobel_v = sobel_h';

limiar_superior = 0.3;
limiar_inferior = 0.0;

device = imaqhwinfo.device;
obj = videoinput("v4l2", device);
set(obj, "VideoResolution", [255 255]);
preview(obj);
start(obj);

snapshot_inicial = getsnapshot(obj);
snapshot_inicial = rgb2gray(snapshot_inicial);
snapshot_inicial = uint8(filter2(sobel_v, snapshot_inicial));
soma_snapshot = mean2(snapshot_inicial);

"Snapshot capturado"

preview(obj);
start(obj);
while(true)
	sleep(1)
	img = getsnapshot(obj);
	img_pb = rgb2gray(img);
	img_pb = uint8(filter2(sobel_v, img_pb));
	soma_img = mean2(img_pb);

	diferenca = abs(soma_snapshot - soma_img)

	imshow(img_pb);
	if((diferenca > limiar_inferior) && (diferenca < limiar_superior))
		MSG
	else
		MSG2
	endif
endwhile
