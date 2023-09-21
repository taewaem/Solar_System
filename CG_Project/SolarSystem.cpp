#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<cstdlib>
#include<ctime>

static int Time = 0, Day2 = 0, Day3 = 0, Day4 = 0, Day5 = 0, Day6 = 0, Day7 = 0, Day8 = 0, Day9 = 0, Day10 = 0;
static float zoom = 1.0;
static int viewMode = 0;						// 0: �⺻ ����, 1: �� ����, 2: �� ����, 3: �� ����, 4: ������ ����
static GLfloat rotation = 0.0f;					// �ʱ� ȸ�� ��
static int speed = 80;							// �ӵ� ����, ���� ����
bool isPaused = false; // �Ͻ����� ����
		/* ���� ������ ���� */
static double R2 = 0.9, G2 = 0.8, B2 = 0.1; //��		 
static double R3 = 0, G3 = 0.5, B3 = 1.0;	//��
static double R4 = 0.0, G4 = 0, B4 = 1.0; //��
static double R5 = 0.6, G5 = 0, B5 = 0;   //ȭ
static double R6 = 0.5, G6 = 0.5, B6 = 0.5; //��
static double R7 = 0.8, G7 = 0.6, B7 = 0.4; //��
static double R8 = 0.7, G8 = 0.7, B8 = 0.7; //��
static double R9 = 0.4, G9 = 0.6, B9 = 0.9; //õ
static double R10 = 0, G10 = 0.3, B10 = 1.0; //��

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glScalef(zoom, zoom, 1.0f);  // ����/�ܾƿ� ����

	glRotatef(rotation, 0.0f, 0.0f, 1.0f);  // ȸ�� ����

	// ���� ����
	switch (viewMode)
	{
	case 0: // �⺻ ����
		gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.5, 0.0);
		break;
	case 1: // �� ����
		gluLookAt(0.1, 0.1, zoom, 0.1, 0.0, 0.0, 1.0, 1.5, 0.0);
		break;
	case 2: // �� ����
		gluLookAt(zoom, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.5, 0.0);
		break;
	case 3: // �� ����
		gluLookAt(0.1, zoom, 0.1, 0.1, 0.0, 0.0, 0.0, 1.0, 0.0);
		break;
	case 4: // ������ ����
		gluLookAt(0.5, 0.5, zoom, 0.1, 0.0, 0.0, 1.0, 1.5, 0.0);
		break;
	default:
		gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.5, 0.0);
		break;
	}

	glColor3f(1.0, 0.3, 0.3); // �¾��� ����
	glutWireSphere((1.0) / 4, 20, 16); // �¾� �׸���

	glPushMatrix();
	glRotatef((GLfloat)Day4, 0.0, 1.0, 0.0);
	glTranslatef(0.45, 0.0, 0.0); // �¾����κ����� �Ÿ�: ����
	glColor3f(R4, G4, B4); // ������ ����
	glutWireSphere((0.1) / 4, 10, 8); // ���� �׸���
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat)Day2, 0.0, 1.0, 0.0);
	glTranslatef(0.6, 0.0, 0.0); // �¾����κ����� �Ÿ�: �ݼ�
	glColor3f(R2, G2, B2); // �ݼ��� ����
	glutWireSphere((0.25) / 4, 10, 8); // �ݼ� �׸���
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat)Day3, 0.0, 1.0, 0.0);
	glTranslatef(1.0, 0.0, 0.0); // �¾����κ����� �Ÿ�: ����
	glColor3f(R3, G3, B3); // ������ ����
	glutWireSphere((0.25) / 4, 10, 8); // ���� �׸���

	glPushMatrix();
	glRotatef((GLfloat)Day6, 0.0, 1.0, 0.0);
	glTranslatef(0.2, 0.0, 0.0); // �����κ����� �Ÿ�: ��
	glColor3f(R6, G6, B6); // ���� ����
	glutWireSphere((0.06) / 4, 10, 8); // �� �׸���
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat)Day5, 0.0, 1.0, 0.0);
	glTranslatef(1.35, 0.0, 0.0); // �¾����κ����� �Ÿ�: ȭ��
	glColor3f(R5, G5, B5); // ȭ���� ����
	glutWireSphere((0.125) / 4, 10, 8); // ȭ�� �׸���
	glPopMatrix();


	glPushMatrix();
	glRotatef((GLfloat)Day7, 0.0, 1.0, 0.0);
	glTranslatef(1.55, 0.0, 0.0); // �¾����κ����� �Ÿ�: ��
	glColor3f(R7, G7, B7); // ���� ����
	glutWireSphere((0.4) / 4, 10, 8); // �� �׸���
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat)Day8, 0.0, 1.0, 0.0);
	glTranslatef(1.85, 0.0, 0.0); // �¾����κ����� �Ÿ�: �伺
	glColor3f(R8, G8, B8); // �伺�� ����
	glutWireSphere((0.3) / 4, 10, 8); // �伺 �׸���
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat)Day9, 0.0, 1.0, 0.0);
	glTranslatef(2.15, 0.0, 0.0); // �¾����κ����� �Ÿ�: õ�ռ�
	glColor3f(R9, G9, B9); // õ�ռ��� ����
	glutWireSphere((0.16) / 4, 10, 8); // õ�ռ� �׸���
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat)Day10, 0.0, 1.0, 0.0);
	glTranslatef(2.45, 0.0, 0.0); // �¾����κ����� �Ÿ�: ���ռ�
	glColor3f(R10, G10, B10); // ���ռ��� ����
	glutWireSphere((0.15) / 4, 10, 8); // ���ռ� �׸���
	glPopMatrix();

	glutSwapBuffers();

}

void MyTimer(int Value)
{
	if (!isPaused) {
		Day2 = (Day2 + 16) % 360;  // �ݼ�: 0.6 ���� �⿡ 1ȸ��
		Day3 = (Day3 + 10) % 360;  // ����: 1 ���� �⿡ 1ȸ��
		Day4 = (Day4 + 25) % 360;  // ����: 0.25 ���� �⿡ 1ȸ��
		Day5 = (Day5 + 2) % 360;  // ȭ��: 1.9 ���� �⿡ 1ȸ��
		Day6 = (Day6 + 70) % 360;  // ��: 0.07 ���� �⿡ 1ȸ��
		Day7 = (Day7 + 7) % 360;  // ��: 1.2 ���� �⿡ 1ȸ��
		Day8 = (Day8 + 6) % 360;  // �伺: 1.2 ���� �⿡ 1ȸ��
		Day9 = (Day9 + 5) % 360;  // õ�ռ�: 1.1 ���� �⿡ 1ȸ��
		Day10 = (Day10 + 4) % 360;  // ���ռ�: 1.1 ���� �⿡ 1ȸ��
	}
	//�Ͻ� ����
	else {
		Day2 = (Day2) % 360;
		Day3 = (Day3) % 360;
		Day4 = (Day4) % 360;
		Day5 = (Day5) % 360;
		Day6 = (Day6) % 360;
		Day7 = (Day7) % 360;
		Day8 = (Day8) % 360;
		Day9 = (Day9) % 360;
		Day10 = (Day10) % 360;
	}
	glutPostRedisplay();         // MyDisplay�� �ٽ� ȣ���Ѵ�.
	glutTimerFunc(speed, MyTimer, 1);       // Ÿ�̸��ݹ��� �ٽ� ȣ���Ѵ�.
}

void MyKeyboard(unsigned char key, int x, int y)
{
	switch (key) {
		// +Ű�� �Է� ������ �ӵ� ����
	case '+':
		speed -= 10;  // ȣ�� ������ �� ª���Ͽ� �ӵ� ����
		if (speed < 10)
			speed = 10;  // �ּ� ȣ�� ���� ����
		glutTimerFunc(speed, MyTimer, 1);  // Ÿ�̸� ȣ�� ���� ����
		break;
		// -Ű�� �Է� ������ �ӵ� ����
	case '-':
		speed += 10;  // ȣ�� ������ �� ����Ͽ� �ӵ� ����
		if (speed > 160)
			speed = 160;  // �ִ� ȣ�� ���� ����
		glutTimerFunc(speed, MyTimer, 1);  // Ÿ�̸� ȣ�� ���� ����
		break;
		// �����̽� �ٸ� �Է� ������ �Ͻ�����
	case ' ':
		isPaused = !isPaused;
		break;
	default:
		break;
	}

}

void SpecialInput(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP: // �� ȭ��ǥ Ű: ����
		zoom += 0.1;
		break;
	case GLUT_KEY_DOWN: // �Ʒ� ȭ��ǥ Ű: �ܾƿ�
		zoom -= 0.1;
		break;
	case GLUT_KEY_LEFT: // ���� ȭ��ǥ Ű: ���� ȸ��
		rotation -= 5.0f;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT: // ������ ȭ��ǥ Ű: ������ ȸ��
		rotation += 5.0f;
		glutPostRedisplay();
		break;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		float random = (float)rand() / RAND_MAX;
		float random1 = (float)rand() / RAND_MAX;
		float random2 = (float)rand() / RAND_MAX;

		R2 = random, G2 = random1, B2 = random2;
		R3 = random1, G2 = random, B2 = random1;
		R4 = random1, G2 = random1, B2 = random2;
		R5 = random2, G2 = random, B2 = random;
		R6 = random1, G2 = random2, B2 = random;
		R7 = random2, G2 = random, B2 = random1;
		R8 = random, G2 = random1, B2 = random2;
		R9 = random2, G2 = random2, B2 = random2;
		R10 = random2, G2 = random1, B2 = random1;
	}
}

void popupMenu(int value)
{
	switch (value)
	{
	case 1:
		glutSetWindowTitle("�⺻ ����");
		viewMode = 0;
		break;
	case 2:
		glutSetWindowTitle("�� ����");
		viewMode = 1;
		break;
	case 3:
		glutSetWindowTitle("�� ����");
		viewMode = 2;
		break;
	case 4:
		glutSetWindowTitle("�� ����");
		viewMode = 3;
		glutPostRedisplay();
		break;
	case 5:
		glutSetWindowTitle("������ ����");
		viewMode = rand() % 4;							//���� ���� �������� 0~3�������� ���� ����
		glutPostRedisplay();
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("20194022_���¿�_TermProject");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.5, 2.5, -2.5, 2.5, -2.5, 2.5);

	glutCreateMenu(popupMenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddMenuEntry("�⺻ ����", 1);
	glutAddMenuEntry("�� ����", 2);
	glutAddMenuEntry("�� ����", 3);
	glutAddMenuEntry("�� ����", 4);
	glutAddMenuEntry("������ ����", 5);


	glutDisplayFunc(MyDisplay);
	glutTimerFunc(speed, MyTimer, 1);
	glutMouseFunc(mouse);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(SpecialInput);
	glutMainLoop();
	return 0;
}