system("ls -l /home/ccm/Downloads/OCTAVE | grep jpeg | wc -l > qtd_imagens");
qtd_frames = load("qtd_imagens");

erro="FALHA NA AUTENTICACAO!!!";

a1 = imread("/home/ccm/Downloads/OCTAVE/im10.jpeg");
b1 = rgb2gray(a1);
#c1 = sum(diag(b1));

for i = 1:qtd_frames
	a2 = imread(sprintf("/home/ccm/Downloads/OCTAVE/im%d.jpeg",i));
	b2 = rgb2gray(a2);
#	c2 = sum(diag(b2));
	result=abs(b2-b1);
	if (result==0)
		system("google-chrome");
	else
		erro
	endif
end
