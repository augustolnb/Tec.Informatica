clear all
clc
FDetect=vision.CascadeObjectDetector;
I= imread('tvd.jpg');
BB=step(FDetect,I);
figure
imshow(I); hold on
for i =1:size(BB,1)
	rectangle('Position',BB(i,:),'LineWidth,5,LineStyle,'-','EdgeColor','r');
end
title('Face Detection');
hold off;
