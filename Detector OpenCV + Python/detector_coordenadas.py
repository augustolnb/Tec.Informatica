#!/usr/bin/env python
# -*- coding: utf-8 -*-

import numpy as np
import cv2
import math
import random
import time

class IdentificarObjeto:

	def __init__(self):
		cv2.namedWindow("Janela", cv2.CV_WINDOW_AUTOSIZE)
		self.scale_down = 4

	def run(self):
		def gerarCoordenada(xMax, yMax):
			x = random.sample(xrange(xMax), 1) 
			y = random.sample(xrange(yMax), 1) 
			x = int(''.join(map(str, x))) 
			y = int(''.join(map(str, y))) 
			coordenada = [x, y]
			return coordenada

		while True:
			# Cria uma imagem com fundo preto, este é representado por largura(y) e altura(x),
			# os outros itens criados são representados por largura(x) e altura(y)
			# Este frame será utilizado para execução de processos necessários
			# para os fins desejados
			bgNew = np.zeros((420,640,3), np.uint8)
			
			# Área de verificação
			# Posição do limite do X inicial
			posXLI = 50
			# Posição do limite do Y inicial
			posYLI = 50
			# Posição do limite do X Final
			posXFI = 200
			# Posição do limite do Y Final
			posYFI = 200
			cv2.rectangle(bgNew,(posXLI,posYLI),(posXFI,posYFI),(255,255,255),3)
			
			coord = gerarCoordenada(600,400)
			coord1 = gerarCoordenada(600,400)
			cv2.rectangle(bgNew, (coord[0], coord[1]), (coord[0]+30, coord[1]+30), (255, 0, 0), -1)
			cv2.rectangle(bgNew, (coord1[0], coord1[1]), (coord1[0]+30, coord1[1]+30), (0, 0, 255), -1)
			
			
			# Definindo padrão de cores a ser detectado
			##################################################
			# No momento esta sendo buscado tons de vermelho #
			##################################################
			# Limite inferior de pigmentação a ser filtrado
			color_lower = np.array([0,0,0],np.uint8)
			#color_upper = np.array([0, 240, 160], np.uint8)
			
			# Limite superior de pigmentação a ser filtrado
			color_upper = np.array([255,0,0], np.uint8)
			#color_lower = np.array([255, 0, 0],np.uint8)
			# Conversão de pigmentação a ser filtrado para binario
			color_binary = cv2.inRange(bgNew, color_lower, color_upper)
			
			# Preparando variavel auxiliar para dilatação de cor
			dilation = np.ones((15,15), 'uint8')
			# Dilatando cor do binario e atribuindo a mesma variável
			color_binary = cv2.dilate(color_binary, dilation)
			
			# Procurando por contorno de objetos em relação ao valor binario
			contours, hierarchy = cv2.findContours(color_binary, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
			
			# Iniciando variáveis de identificação de objeto
			max_area = 0
			largest_contour = None
			points = []
			font = cv2.FONT_HERSHEY_SIMPLEX
			
			
			for idx, contour in enumerate(contours):
				area = cv2.contourArea(contour)
				if area > max_area:
					max_area = area
					largest_contour = contour
			
			if not largest_contour == None:
				moment = cv2.moments(largest_contour)
				if coord[0] >= posYLI and coord[0] <= posYFI and coord[1] >= posXLI and coord[1] <= posXFI:
					if moment["m00"] > 1000 / self.scale_down:
						rect = cv2.minAreaRect(largest_contour)
						pt1 = (rect[0][0] * self.scale_down, rect[0][1] * self.scale_down)
						pt2 = (rect[1][0] * self.scale_down, rect[1][1] * self.scale_down)
						rect = (pt1, pt2 , rect[2])
						points.append(pt1)
						points.append(pt2)
						box = cv2.cv.BoxPoints(rect)
						box = np.int0(box)
						posX = cv2.cv.Round((pt1[0]+pt2[0])/2)
						posY = cv2.cv.Round((pt1[1]+pt2[1])/2)

						cv2.putText(bgNew,'Dentro',(10,300), font, 4,(0,255,0),2)
				else:
					cv2.putText(bgNew,'Fora',(10,300), font, 4,(0,255,0),2)
				time.sleep(2)
			cv2.imshow("Janela", bgNew)
			time.sleep(0.5)
			if cv2.waitKey(20) == 27:
				cv2.destroyWindow("Janela")
				bg.release()
				break

# Inicializa a classe
if __name__ == "__main__":
	identificarObjeto = IdentificarObjeto()
	identificarObjeto.run()
