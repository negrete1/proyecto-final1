//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//Solo para Visual Studio 2015
#if (_MSC_VER == 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

CCamera objCamera; 
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 27.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01
CTexture fachadaPrincipal;
CTexture fachadaParedes;
CTexture ventanal;
CTexture piso;
CTexture textder;
CTexture alfombra;
CTexture techo;
CTexture sillon;
CTexture lampn;
CTexture lampp;
CTexture lino;
CTexture madera;
CTexture negro;
CTexture dvd;
CTexture dvd1;
//CTexture pantalla;
CTexture cojin;
CTexture cojin1;
CTexture marco;
CTexture florero;
CTexture florero1;
CTexture conoverde;
CTexture conoazul;
CTexture conorosa;
CTexture ajedrez;
CTexture velas;
CTexture velas1;
CTexture piezas;
CTexture libros;
CTexture libros1;
CTexture libros2;
CTexture libros3;

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;

CFiguras fig7; //Para el monito
CFiguras miobj;

//Figuras de 3D Studio
CModel kit;
CModel llanta;

//Animación del coche
float movKit = 0.0;
bool g_fanimacion = false;

			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	glEnable(GL_BLEND);			// Turn Blending On
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("logopumas.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("city/pantalla.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("fachada.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();

	fachadaPrincipal.LoadTGA("fachada.tga");
	fachadaPrincipal.BuildGLTexture();
	fachadaPrincipal.ReleaseImage();

	///////////////////////textura paredes///////////////////////////////////////

	fachadaParedes.LoadTGA("ladrillo.tga");
	fachadaParedes.BuildGLTexture();
	fachadaParedes.ReleaseImage();

	////////////////////////////ventanal////////////////////

	ventanal.LoadTGA("ventanal.tga");
	ventanal.BuildGLTexture();
	ventanal.ReleaseImage();

	/////////////////////////////////////piso///////////////////////////77

	piso.LoadTGA("piso.tga");
	piso.BuildGLTexture();
	piso.ReleaseImage();

	////////////////////////////////textura derecha/////////////////////////////77
	textder.LoadTGA("paredderecha.tga");
	textder.BuildGLTexture();
	textder.ReleaseImage();

	///////////////////////////////7alfombra///////////////////////////////7

	alfombra.LoadTGA("alfombra.tga");
	alfombra.BuildGLTexture();
	alfombra.ReleaseImage();

	////////////////////////////////////////////////techo//////////////////////////////////////////

	techo.LoadTGA("techo.tga");
	techo.BuildGLTexture();
	techo.ReleaseImage();

	////////////////////////sillon cafe////////////////////////////

	sillon.LoadTGA("gamusa.tga");
	sillon.BuildGLTexture();
	sillon.ReleaseImage();

	/////////////////////////////////lampara///////////////////////////////////////
	lampn.LoadTGA("negro.tga");
	lampn.BuildGLTexture();
	lampn.ReleaseImage();

	lampp.LoadTGA("plata.tga");
	lampp.BuildGLTexture();
	lampp.ReleaseImage();

	lino.LoadTGA("lino.tga");
	lino.BuildGLTexture();
	lino.ReleaseImage();
	//////////////////////textura muebles madera///////////////////////////

	madera.LoadTGA("madera.tga");
	madera.BuildGLTexture();
	madera.ReleaseImage();

	//////////////separacion de cajones/////////////77
	negro.LoadTGA("negro.tga");
	negro.BuildGLTexture();
	negro.ReleaseImage();

	dvd.LoadTGA("dvd.tga");
	dvd.BuildGLTexture();
	dvd.ReleaseImage();

	dvd1.LoadTGA("dvd1.tga");
	dvd1.BuildGLTexture();
	dvd1.ReleaseImage();
	////////pantalla

	marco.LoadTGA("marco.tga");
	marco.BuildGLTexture();
	marco.ReleaseImage();

	/////////////////////////cojin

	cojin.LoadTGA("cojin.tga");
	cojin.BuildGLTexture();
	cojin.ReleaseImage();

	cojin1.LoadTGA("cojin1.tga");
	cojin1.BuildGLTexture();
	cojin1.ReleaseImage();

	///florero

	florero.LoadTGA("florero.tga");
	florero.BuildGLTexture();
	florero.ReleaseImage();


	florero1.LoadTGA("florero1.tga");
	florero1.BuildGLTexture();
	florero1.ReleaseImage();
	///cono verde
	conoverde.LoadTGA("cono verde.tga");
	conoverde.BuildGLTexture();
	conoverde.ReleaseImage();

	conoazul.LoadTGA("azul.tga");
	conoazul.BuildGLTexture();
	conoazul.ReleaseImage();
	
	conorosa.LoadTGA("rosa.tga");
	conorosa.BuildGLTexture();
	conorosa.ReleaseImage();
	///////ajedrez
	ajedrez.LoadTGA("ajedrez.tga");
	ajedrez.BuildGLTexture();
	ajedrez.ReleaseImage();
	////////////velas
	velas.LoadTGA("velas.tga");
	velas.BuildGLTexture();
	velas.ReleaseImage();

	velas1.LoadTGA("velas1.tga");
	velas1.BuildGLTexture();
	velas1.ReleaseImage();
	//////////piezas de ajedres
	piezas.LoadTGA("piezas.tga");
	piezas.BuildGLTexture();
	piezas.ReleaseImage();
	//////////libros
	libros.LoadTGA("libros.tga");
	libros.BuildGLTexture();
	libros.ReleaseImage();

	libros1.LoadTGA("libros1.tga");
	libros1.BuildGLTexture();
	libros1.ReleaseImage();

	libros2.LoadTGA("libros2.tga");
	libros2.BuildGLTexture();
	libros2.ReleaseImage();

	libros3.LoadTGA("libros.tga");
	libros3.BuildGLTexture();
	libros3.ReleaseImage();





	//Carga de Figuras
	//kit._3dsLoad("entradaC.3ds");	
	//kit.VertexNormals();
	
	//llanta._3dsLoad("k_rueda.3ds");


	objCamera.Position_Camera(10,2.5f,13, 10,2.5f,10, 0, 1, 0);

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}



void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
	glPushMatrix();

		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
				//Para que el coche conserve sus colores
				glDisable(GL_COLOR_MATERIAL);
				glRotatef(42, 0, 1, 0);
			
				glTranslatef(0.5, 3, -6);
				
				//Pongo aquí la carroceria del carro

				kit.GLrender(NULL,_SHADED,1.0);  //_WIRED O _POINTS
				
				llanta.GLrender(NULL,_SHADED,1.0);
				
			glPopMatrix();

			//Para que el comando glColor funcione con iluminacion
			glEnable(GL_COLOR_MATERIAL);
			
			glPushMatrix(); //Flecha
			glTranslatef(1.2, 2.5, -10.0);
			glRotatef(90, 0, 0, 1);
				glScalef(1.0,0.1,1.5);//x ancho y profundidad z largo
				glDisable(GL_LIGHTING);
				fig3.prisma_anun(text3.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //Camino1
				glTranslatef(23.5,0.0,0.0);
				glScalef(40,0.1,7);
				glDisable(GL_LIGHTING);
				fig3.prisma2(text4.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //Camino2
				glTranslatef(-23.5,0.0,0.0);
				glScalef(40,0.1,7);
				glDisable(GL_LIGHTING);
				fig3.prisma2(text4.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //Pasto
				glTranslatef(0.0,0.0,-4.0);
				glScalef(87,0.1,1);
				glDisable(GL_LIGHTING);
				fig4.prisma2(text5.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //Pasto
				glTranslatef(0.0,0.0,4.0);
				glScalef(87,0.1,1);
				glDisable(GL_LIGHTING);
				fig4.prisma2(text5.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			//glPushMatrix(); //Casa01
			//	glTranslatef(0.0,3.0,7.0);
			//	glRotatef(90,1,0,0);
			//	glRotatef(180,0,0,1);
			//	glScalef(6,5.0,6);
			//	glDisable(GL_LIGHTING);
			//	fig5.prisma2(text6.GLindex, 0);
			//	glEnable(GL_LIGHTING);

			//	glPushMatrix(); //Casa01
			//	glTranslatef(0.0, 3.0, 7.0);
			//	glRotatef(-90, 1, 0, 0);
			//	glRotatef(180, 0, 0, 1);
			//	glScalef(6, 5.0, 6);
			//	glDisable(GL_LIGHTING);
			//	fig5.prisma2(text6.GLindex, 0);
			//	glEnable(GL_LIGHTING);
			//	glPopMatrix();

			//	glPopMatrix();


			//glPushMatrix(); //Casa01
			//	glTranslatef(0.0,3.0,-7.0);
			//	glRotatef(90,1,0,0);
			//	glScalef(6,5.0,6);
			//	glDisable(GL_LIGHTING);
			//	fig5.prisma2(text6.GLindex, 0);
			//	glEnable(GL_LIGHTING);
			//glPopMatrix();


			glPushMatrix(); //Pared #fondo
			glTranslatef(-3, 3.1, -17.4);
			glRotatef(270, 1, 0, 0);
			//glRotatef(180,0,0,1);
			glScalef(12, 0.25, 6.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(fachadaParedes.GLindex, fachadaParedes.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix(); //Pared fondo
			glTranslatef(-3, 3.1, -17.2);
			glRotatef(-270, 1, 0, 0);
			//		glRotatef(-90, 1, 0, 0);
					//glRotatef(180,0,0,1);
			glScalef(11.5, 0.05, 6.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(ventanal.GLindex, fachadaParedes.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix(); //Pared #entrada
			glTranslatef(-3.1, 3.0, -4.6);
			glRotatef(90, 1, 0, 0);
			//glRotatef(180,0,0,1);
			glScalef(11.9, 0.25, 5.9);
			glDisable(GL_LIGHTING);
			fig5.prisma2(fachadaPrincipal.GLindex, fachadaParedes.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix(); //Pared #entrada-azul
			glTranslatef(-3, 3.0, -4.8);
			glRotatef(-90, 1, 0, 0);
			//glRotatef(180,0,0,1);
			glScalef(12, 0.05, 6.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(textder.GLindex, fachadaParedes.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix(); //Pared #izquierda
			glTranslatef(-8.9, 3.1, -11.0);
			//glTranslatef(-35.0, 3.2, -4.6);
			glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);
			glScalef(13, 0.25, 6.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(fachadaParedes.GLindex, fachadaParedes.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix(); //Pared #izquierda-azul
			glTranslatef(-8.7, 3.1, -11.0);
			//glTranslatef(-35.0, 3.2, -4.6);
			glRotatef(-90, 0, 90, 1);
			glRotatef(90, -45, 0, 0);
			glScalef(13, 0.05, 6.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(textder.GLindex, 0);
			glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix(); //Pared #derecha
			glTranslatef(2.9, 3.1, -11.0);
			//glTranslatef(-35.0, 3.2, -4.6);
			glRotatef(-90, 0, 90, 1);
			glRotatef(90, -45, 0, 0);
			glScalef(13, 0.25, 6.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(fachadaParedes.GLindex, fachadaParedes.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix(); //Pared #derecha
			glTranslatef(2.7, 3.1, -11.0);
			//glTranslatef(-35.0, 3.2, -4.6);
			glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);
			glScalef(13, 0.05, 6.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(textder.GLindex, 0);
			glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix(); //Pared #techo
			glTranslatef(-3, 6.05, -11);
			glRotatef(90, 1, 0, 0);
			glRotatef(90, 90, 0, 0);
			glScalef(11.9, 0.1, 12.9);
			glDisable(GL_LIGHTING);
			fig5.prisma2(techo.GLindex, fachadaParedes.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix(); //Pared #piso
			glTranslatef(-3, 0.2, -11);
			glRotatef(90, 1, 0, 0);
			glRotatef(-90, 90, 0, 0);
			glScalef(12, 0.05, 13);
			glDisable(GL_LIGHTING);
			fig5.prisma2(piso.GLindex, fachadaParedes.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();


			///////////////alfombra /////////////////

			glPushMatrix(); //Alfombra
			glTranslatef(-3, 0.3, -11);
			glRotatef(90, 1, 0, 0);
			glRotatef(-90, 90, 0, 0);
			glScalef(4, 0.05, 4);
			glDisable(GL_LIGHTING);
			fig5.prisma2(alfombra.GLindex, 0);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			

			/////////////////////////////////muebles///////////////////////////////
			
			//////////////mueble negro//////////////77
			glPushMatrix();
			glTranslatef(-2.0f, 0.7f, -6.5f);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1f);
			miobj.prisma(0.7, 1.2, 1.2, sillon.GLindex);
			glDisable(GL_ALPHA_TEST);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-2.5f, 0.2f, -7.0f);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1f);
			miobj.cilindro(0.08, 0.2, 25, sillon.GLindex);
			glDisable(GL_ALPHA_TEST);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-2.5f, 0.2f, -6.0f);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1f);
			miobj.cilindro(0.08, 0.2, 25, sillon.GLindex);
			glDisable(GL_ALPHA_TEST);
			glPopMatrix();


			glPushMatrix();
			glTranslatef(-1.5f, 0.2f, -7.0f);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1f);
			miobj.cilindro(0.08, 0.2, 25, sillon.GLindex);
			glDisable(GL_ALPHA_TEST);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-1.5f, 0.2f, -6.0f);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1f);
			miobj.cilindro(0.08, 0.2, 25, sillon.GLindex);
			glDisable(GL_ALPHA_TEST);
			glPopMatrix();
			
			//////////////////////////////lampara////////////////////////////////////////////
			
			///negro
			glPushMatrix();
			glTranslatef(-0.9f, 0.0f, -16.0f);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1f);
			miobj.cilindro(0.10, 2.0, 25, lampn.GLindex);
			glDisable(GL_ALPHA_TEST);
			glPopMatrix();

			////dorado
			glPushMatrix();
			glTranslatef(-0.9f, 2.0f, -16.0f);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1f);
			miobj.cilindro(0.10, 1, 25, lampp.GLindex);
			glDisable(GL_ALPHA_TEST);
			glPopMatrix();
			//////cabeza

			glPushMatrix();
			glTranslatef(-0.9f, 3.0f, -16.0f);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1f);
			miobj.cilindro(0.5, 0.8, 25, lino.GLindex);
			glDisable(GL_ALPHA_TEST);
			glPopMatrix();

			////////////////mueble esquinero///////////////////////////7
			//trasera
			glPushMatrix(); 
			glTranslatef(1.1, 2.0, -16.35);
			glRotatef(90, 0, 1, 0);
			//glRotatef(-90, -45, 0, 0);
			glScalef(0.2, 3.5, 1.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			////izquierda/////////////

			glPushMatrix(); 
			glTranslatef(0.5, 2.0, -15.95);
			//glRotatef(90, 0, 1, 0);
			//glRotatef(90, -45, 0, 0);*/
			glScalef(0.2, 3.8, 1.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			//////////////derecho////////////////77

			glPushMatrix(); 
			glTranslatef(1.7,2.0,-15.95);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(0.2, 3.8, 1.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();


			//////piso mueble///////////

			glPushMatrix();
			glTranslatef(1.1, 0.3, -15.95);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.2, 1.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			//////techo mueble///////////

			glPushMatrix();
			glTranslatef(1.1, 3.8, -15.95);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.2, 1.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			//////////////divisiones////////////////////7

			glPushMatrix();
			glTranslatef(1.1, 1.2, -15.95);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.04, 1.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.1, 2.1, -15.95);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.04, 1.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.1, 3.0, -15.95);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.04, 1.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			/////////////////centro de entretenimiento//////////////////////////////////77
			//////tercia izquierda/////////////
			glPushMatrix();
			glTranslatef(1.2, 3.7, -12.5);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.2, 2.5);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2, 2.0, -11.35);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 3.2, 0.2);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2, 2.0, -13.65);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 3.2, 0.2);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2, 0.3, -12.5);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.2, 2.5);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			/////////////divisiones//////////////////77

			glPushMatrix();
			glTranslatef(1.2, 2.4, -12.5);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 2.4, 0.3);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2, 0.75, -12.5);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.9, 2.5);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			
			/////////cuadros cajon derecho
			glPushMatrix();
			glTranslatef(1.19, 1.8, -11.92);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.15, 0.95);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.19, 2.4, -11.92);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.15, 0.95);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.19, 3.0, -11.92);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.15, 0.95);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			/////////cuadros cajon izquierdo

			glPushMatrix();
			glTranslatef(1.19, 1.8, -13.07);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.15, 0.95);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.19, 2.4, -13.07);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.15, 0.95);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.19, 3.0, -13.07);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.15, 0.95);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			/////////////////////manijas de cajones 
			glPushMatrix();
			glTranslatef(1.1, 2.4, -12.4);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.3, 0.04);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.1, 2.4, -12.6);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.3, 0.04);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			
			//lineas negras
			glPushMatrix();
			glTranslatef(1.18, 2.4, -12.5);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 2.4, 0.04);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.19, 0.4, -12.5);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.04, 2.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.19, 1.0, -12.5);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.04, 2.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.19, 0.7, -12.5);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.6, 0.04);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.19, 0.7, -11.5);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.6, 0.04);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.19, 0.7, -13.5);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.6, 0.04);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			/////////////////manijas 

			glPushMatrix();
			glTranslatef(1.1, 0.7, -12.3);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.1, 0.05);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.1, 0.7, -12.7);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.1, 0.05);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			////////////////////////medio////////////////////////////////////////7

			glPushMatrix();
			glTranslatef(1.2, 0.4, -10.0);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.3, 2.5);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2, 0.8, -10.0);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.6, 2.5);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			//////lineas de cajones 
			//////horizontales
			glPushMatrix();
			glTranslatef(0.79, 1.0, -10.0);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(0.2, 0.04, 2.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.79, 0.5, -10.0);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(0.2, 0.04, 2.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			///////manijas

			glPushMatrix();
			glTranslatef(0.70, 0.75, -10.65);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(0.2, 0.04, 0.15);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.70, 0.75, -9.99);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(0.2, 0.04, 0.15);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.70, 0.75, -9.33);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(0.2, 0.04, 0.15);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			

			//////////vericales/////////////////

			glPushMatrix();
			glTranslatef(0.79, 0.75, -9.0);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(0.2, 0.5, 0.04);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.79, 0.75, -9.66);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(0.2, 0.5, 0.04);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.79, 0.75, -10.32);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(0.2, 0.5, 0.04);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.79, 0.75, -11.0);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(0.2, 0.5, 0.04);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			//////////////////////////DvD´s///////////////////////////////

			glPushMatrix();
			glTranslatef(0.79, 1.2, -9.5);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(0.02, 0.2, 0.9);
			glDisable(GL_LIGHTING);
			fig5.prisma2(dvd.GLindex, dvd.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.79, 1.2, -10.5);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(0.02, 0.2, 0.9);
			glDisable(GL_LIGHTING);
			fig5.prisma2(dvd1.GLindex, dvd1.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			////////////dvd arriba
			glPushMatrix();
			glTranslatef(1.2, 1.2, -11.0);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.7, 0.3);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2, 1.2, -8.9);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.7, 0.3);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2, 1.6, -10.0);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.3, 2.5);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			//////////////////marco pantalla////////////////////////////

			glPushMatrix();
			glTranslatef(1.2,3.05, -10.0);
			/*glRotatef(90, 1, 0, 0);*/
			//glRotatef(-90, -45, 0, 0);
			glScalef(0.2, 0.1, 1.8);
			glDisable(GL_LIGHTING);
			fig3.prisma_anun(marco.GLindex, marco.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2, 2.0, -10.0);
			/*glRotatef(90, 1, 0, 0);*/
			//glRotatef(-90, -45, 0, 0);
			glScalef(0.2, 0.1, 1.8);
			glDisable(GL_LIGHTING);
			fig3.prisma_anun(marco.GLindex, marco.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2, 2.5, -10.8);
			/*glRotatef(90, 1, 0, 0);*/
			//glRotatef(-90, -45, 0, 0);
			glScalef(0.1, 1.0, 0.2);
			glDisable(GL_LIGHTING);
			fig3.prisma_anun(marco.GLindex, marco.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2, 2.5, -9.2);
			/*glRotatef(90, 1, 0, 0);*/
			//glRotatef(-90, -45, 0, 0);
			glScalef(0.1, 1.0, 0.2);
			glDisable(GL_LIGHTING);
			fig3.prisma_anun(marco.GLindex, marco.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix();
			glTranslatef(1.2f, 1.7f, -10.0f);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1f);
			miobj.cilindro(0.15, 0.25, 25, marco.GLindex);
			glDisable(GL_ALPHA_TEST);
			glPopMatrix();
			//////////////////////////////////////////////////mueble derecho///////////////////////////////////////////////////
			//base 
			glPushMatrix();
			glTranslatef(1.2, 0.4, -7.15);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.3, 2.5);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			//////techo
			glPushMatrix();
			glTranslatef(1.2, 3.6, -7.15);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.3, 2.5);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			///////////////verticales izquierdo
			glPushMatrix();
			glTranslatef(1.2, 2.0, -8.55);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 3.5, 0.3);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			//////////verticales derecho
			glPushMatrix();
			glTranslatef(1.2, 2.0, -6.0);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 3.5, 0.3);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			/////////divisiones horizontales
			glPushMatrix();
			glTranslatef(1.2, 2.15, -7.3);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.04, 2.3);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix();
			glTranslatef(1.2, 2.73, -7.3);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.04, 2.3);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			//////divisiones verticales
			glPushMatrix();
			glTranslatef(1.2, 2.45, -7.2);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.6, 0.04);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2, 3.09, -7.6);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.7, 0.04);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2, 3.09, -6.8);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.7, 0.04);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();




			glPushMatrix();
			glTranslatef(1.2, 1.25, -6.9);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 1.75, 0.04);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2, 1.25, -7.65);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 1.75, 0.04);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			/////////////cajones
			glPushMatrix();
			glTranslatef(1.2, 1.3, -6.52);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.3, 0.75);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2, 0.7, -7.3);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.3, 0.74);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2, 1.0, -7.3);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.3, 0.74);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2, 1.3, -8.02);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.3, 0.7);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			//////////////////////manijas cajones////////////////////////////

			glPushMatrix();
			glTranslatef(1.1, 1.3, -6.52);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.06, 0.2);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.1, 0.7, -7.3);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.06, 0.2);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			
			glPushMatrix();
			glTranslatef(1.1, 1.0, -7.3);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.06, 0.2);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.1, 0.85, -7.3);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.03, 0.74);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix();
			glTranslatef(1.1, 1.3, -8.02);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(1.0, 0.06, 0.2);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro
				.GLindex,negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();


			/////////////////////sillon fondo///////////////////////////
			///////base
			glPushMatrix();
			glTranslatef(-2.7, 0.6, -14.2);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(3.0, 0.7, 1.3);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			/////verticales
			glPushMatrix();
			glTranslatef(-1.0, 1.0, -14.2);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(0.4, 1.4, 1.3);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-4.4, 1.0, -14.2);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(0.4, 1.4, 1.3);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			////////respaldo

			glPushMatrix();
			glTranslatef(-2.7, 1.0, -15.0);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(3.8, 1.4, 0.4);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			///////////cojin/////////////
			glPushMatrix();
			glTranslatef(-2.7, 1.15, -14.2);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(3.0, 0.4, 1.3);
			glDisable(GL_LIGHTING);
			fig5.prisma2(cojin.GLindex, cojin.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-2.7, 1.85, -14.53);
			/*glRotatef(-90, 0, 90, 1);
			glRotatef(-90, -45, 0, 0);*/
			glScalef(3.0, 1.0, 0.4);
			glDisable(GL_LIGHTING);
			fig5.prisma2(cojin.GLindex, cojin.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-2.5, 1.6, -14.1);
			glRotatef(90, 0, 1, 0);
			glRotatef(-90, -45, 0, 0);
			glDisable(GL_LIGHTING);
			miobj.cilindro(0.2, 1.15, 25, cojin1.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-4.0, 1.6, -14.1);
			glRotatef(90, 0, 1, 0);
			glRotatef(-90, -45, 0, 0);
			glDisable(GL_LIGHTING);
			miobj.cilindro(0.2, 1.15, 25, cojin1.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			////////////mesa de centro
			//////////base
			glPushMatrix(); 
			glTranslatef(-3, 0.65, -11);
			glScalef(1.5, 0.6, 2.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			///////verticales
			glPushMatrix();
			glTranslatef(-3, 0.85, -9.85);
			glScalef(1.5, 1.0, 0.3);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-3, 0.85, -12.15);
			glScalef(1.5, 1.0, 0.3);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			///////////////base arriba
			glPushMatrix();
			glTranslatef(-3, 1.45, -11);
			glScalef(1.5, 0.3, 2.6);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			//////////////lineas negras 
			///verticaeles 
			glPushMatrix();
			glTranslatef(-3.30, 0.45, -10.5);
			glScalef(1.0, 0.03, .75);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-3.30, 0.80, -10.5);
			glScalef(1.0, 0.03, .75);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix();
			glTranslatef(-3.30, 0.45, -11.5);
			glScalef(1.0, 0.03, .75);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-3.30, 0.80, -11.5);
			glScalef(1.0, 0.03, .75);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			
			//////////////verticales
			glPushMatrix();
			glTranslatef(-3.30, 0.625, -10.12);
			glScalef(1.0, 0.35, 0.03);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-3.30, 0.625, -10.87);
			glScalef(1.0, 0.35, 0.03);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			/////
			glPushMatrix();
			glTranslatef(-3.30, 0.625, -11.15);
			glScalef(1.0, 0.35, 0.03);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-3.30, 0.625, -11.85);
			glScalef(1.0, 0.35, 0.03);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			////////////////////manijas
			glPushMatrix();
			glTranslatef(-3.30, 0.6, -10.5);
			glScalef(1.0, 0.03, .2);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-3.30, 0.6, -11.5);
			glScalef(1.0, 0.03, .2);
			glDisable(GL_LIGHTING);
			fig5.prisma2(negro.GLindex, negro.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			////////////////mueble izquierdo///////////////////////////////
			
			//cilindros
			glPushMatrix();
			glTranslatef(-5.5f, 0.2f, -9.8f);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1f);
			miobj.cilindro(0.15, 1.4, 25, madera.GLindex);
			glDisable(GL_ALPHA_TEST);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-5.5, 0.2f, -12.45f);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1f);
			miobj.cilindro(0.15, 1.4, 25, madera.GLindex);
			glDisable(GL_ALPHA_TEST);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-6.15, 0.9, -12.45);
			glScalef(1.2, 1.4, 0.30);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-6.15, 0.9, -9.8);
			glScalef(1.2, 1.4, 0.30);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();




			///////////horizontal
			glPushMatrix();
			glTranslatef(-6.15, 0.5, -11.11);
			glScalef(1.2, 0.6, 2.4);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-6.90, 1.2, -11.11);
			glScalef(0.3, 2.0, 3.0);
			glDisable(GL_LIGHTING);
			fig5.prisma2(madera.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			////////////cojines

			glPushMatrix();
			glTranslatef(-6.15, 1.0, -11.11);
			glScalef(1.2, 0.4, 2.4);
			glDisable(GL_LIGHTING);
			fig5.prisma2(cojin.GLindex, cojin.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-6.55, 1.5, -11.11);
			glScalef(0.4, 1.2, 2.2);
			glDisable(GL_LIGHTING);
			fig5.prisma2(cojin.GLindex, cojin.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-6.13, 1.4, -11.0);
			glRotatef(90, 1, 0, 0);
			glDisable(GL_LIGHTING);
			miobj.cilindro(0.2, 1.0, 25, cojin1.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-6.13, 1.4, -12.11);
			glRotatef(90, 1, 0, 0);
			glDisable(GL_LIGHTING);
			miobj.cilindro(0.2, 1.0, 25, cojin1.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			///////////////////////florero////////////////////////////////

			glPushMatrix();
			glTranslatef(0.9, 3.8, -6.35);
			glRotatef(90, 0, 1, 0);
			glDisable(GL_LIGHTING);
			miobj.cilindro(0.2, 0.7, 25, florero.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.9, 3.8, -7.8);
			glRotatef(90, 0, 1, 0);
			glDisable(GL_LIGHTING);
			miobj.cilindro(0.2, 0.7, 25, florero1.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			////////////conos
			glPushMatrix();
			glTranslatef(1.1, 2.8, -8.0);
			glRotatef(90, 0, 1, 0);
			glDisable(GL_LIGHTING);
			miobj.cono(0.5, 0.25, 25, conoverde.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.1, 2.8, -7.2);
			glRotatef(90, 0, 1, 0);
			glDisable(GL_LIGHTING);
			miobj.cono(0.5, 0.25, 25, conoazul.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.1, 2.8, -6.5);
			glRotatef(90, 0, 1, 0);
			glDisable(GL_LIGHTING);
			miobj.cono(0.5, 0.25, 25, conorosa.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			///////////tablero ajedrez
			glPushMatrix();
			glTranslatef(0.9, 0.7, -6.5);
			glScalef(0.5, 0.3, 0.55);
			glDisable(GL_LIGHTING);
			fig5.prisma2(ajedrez.GLindex, ajedrez.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			////////////velas
			glPushMatrix();
			glTranslatef(0.9, 0.7, -8.05);
			glScalef(0.5, 0.3, 0.55);
			glDisable(GL_LIGHTING);
			fig5.prisma2(velas1.GLindex, velas.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			//////piezas de ajedrez
			glPushMatrix();
			glTranslatef(0.9, 1.5, -7.3);
			glRotatef(90, 1, 0, 0);
			glScalef(0.03, 0.6, 0.8);
			glDisable(GL_LIGHTING);
			fig5.prisma2(piezas.GLindex, piezas.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			//////////////libros
			glPushMatrix();
			glTranslatef(0.7, 1.7, -6.5);
			glScalef(0.03, 0.5, 0.65);
			glDisable(GL_LIGHTING);
			fig5.prisma2(libros.GLindex, libros.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.7, 1.7, -8.0);
			glScalef(0.03, 0.5, 0.65);
			glDisable(GL_LIGHTING);
			fig5.prisma2(libros.GLindex, libros.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			///////////////libros mueble esquinero

			glPushMatrix();
			glTranslatef(1.1, 0.6, -15.65);
			glRotatef(90, 0, 1, 0);
			//glRotatef(-90, -45, 0, 0);
			glScalef(0.2, 0.6, 0.85);
			glDisable(GL_LIGHTING);
			fig5.prisma2(libros1.GLindex, libros1.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.1, 1.65, -15.65);
			glRotatef(90, 0, 1, 0);
			glRotatef(90, 1, 0, 0);
			glScalef(0.2, 0.6, 0.85);
			glDisable(GL_LIGHTING);
			fig5.prisma2(libros.GLindex, libros2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.1, 2.51, -15.65);
			glRotatef(90, 0, 1, 0);
			glRotatef(90, 1, 0, 0);
			glScalef(0.2, 0.6, 0.85);
			glDisable(GL_LIGHTING);
			fig5.prisma2(libros3.GLindex, libros3.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.1, 3.1, -15.65);
			glRotatef(90, 0, 1, 0);
			glDisable(GL_LIGHTING);
			miobj.cono(0.5, 0.25, 25, conorosa.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix();
			
			glColor3f(0.5f, 0.5f, 0.5f);
			glTranslatef(-3.0, 2.0, -11.0);
			glutSolidTeapot(0.5);
			//glBegin(GL_LINES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(2.0f, 0.0f, 0.0f);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 2.0f, 0.0f);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 2.0f);
			glEnd();
			glPopMatrix();


			glColor3f(1.0,1.0,1.0);

		glPopMatrix();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
		glColor3f(1.0,0.0,0.0);
		pintaTexto(-12,12.0,-14.0,(void *)font,"Practica 10");
		pintaTexto(-12,10.5,-14,(void *)font,"Poner algo en Movimiento");
		glColor3f(1.0,1.0,1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void animacion()
{
	fig3.text_izq-= 0.001;
	fig3.text_der-= 0.001;
	if(fig3.text_izq<-1)
		fig3.text_izq=0;
	if(fig3.text_der<0)
		fig3.text_der=1;


	if(g_fanimacion)
	{
		movKit +=1.0;
	}

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case ' ':		//Poner algo en movimiento
			g_fanimacion^= true; //Activamos/desactivamos la animacíon
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 10"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}
