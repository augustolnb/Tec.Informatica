pkg load image-acquisition;

MSG1="IMAGEM IGUAL";
MSG2="IMAGEM DIFERENTE";
imagens = dir("img/*.png"); 
filtro = fspecial("sobel", 5, 1);

device = imaqhwinfo.device;

outputFolder = fullfile(cd, 'frames');

if ~exist(outputFolder, 'dir')
	mkdir(outputFolder);
endif

obj = videoinput("v4l2", device);

set(obj, "VideoResolution", [352 288])

preview(obj);

start(obj, 2);

x = 1;

while(true)
	img = getsnapshot(obj);
	% image(img);
	outputBaseFileName = sprintf("ex%d.png", x);
	outputFullFileName = fullfile(outputFolder, outputBaseFileName);
	imwrite(img, outputFullFileName);
	img_pb = rgb2gray(img);
	im_filter = uint8(filter2(filtro, img_pb));
	DIAG1 = sum(diag(im_filter));

	for i = 1 : length(imagens)
		sprintf("Captura %d - comparando com imagem %d.", x, i)
		im2 = imread(strcat("/home/aluno/Desktop/PDI/img/", imagens(i).name));
	    DIAG2 = sum(diag(im2));
	    DIF = abs(DIAG1 - DIAG2);
	    if(DIF <= 400)
	       "Imagem encontrada"
	       	flag = 1;
	        break
	    endif
	endfor

	x++
endwhile

stop(obj);
