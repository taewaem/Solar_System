#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<cstdlib>
#include<ctime>

static int Time = 0, Day2 = 0, Day3 = 0, Day4 = 0, Day5 = 0, Day6 = 0, Day7 = 0, Day8 = 0, Day9 = 0, Day10 = 0;
static float zoom = 1.0;
static int viewMode = 0;						// 0: 기본 시점, 1: 위 시점, 2: 옆 시점, 3: 앞 시점, 4: 무작위 시점
static GLfloat rotation = 0.0f;					// 초기 회전 값
static int speed = 80;							// 속도 증가, 감소 변수
bool isPaused = false; // 일시정지 여부
		/* 색상 변경을 위한 */
static double R2 = 0.9, G2 = 0.8, B2 = 0.1; //금		 
static double R3 = 0, G3 = 0.5, B3 = 1.0;	//지
static double R4 = 0.0, G4 = 0, B4 = 1.0; //수
static double R5 = 0.6, G5 = 0, B5 = 0;   //화
static double R6 = 0.5, G6 = 0.5, B6 = 0.5; //달
static double R7 = 0.8, G7 = 0.6, B7 = 0.4; //목
static double R8 = 0.7, G8 = 0.7, B8 = 0.7; //토
static double R9 = 0.4, G9 = 0.6, B9 = 0.9; //천
static double R10 = 0, G10 = 0.3, B10 = 1.0; //혜

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glScalef(zoom, zoom, 1.0f);  // 줌인/줌아웃 적용

	glRotatef(rotation, 0.0f, 0.0f, 1.0f);  // 회전 적용

	// 시점 변경
	switch (viewMode)
	{
	case 0: // 기본 시점
		gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.5, 0.0);
		break;
	case 1: // 위 시점
		gluLookAt(0.1, 0.1, zoom, 0.1, 0.0, 0.0, 1.0, 1.5, 0.0);
		break;
	case 2: // 옆 시점
		gluLookAt(zoom, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.5, 0.0);
		break;
	case 3: // 앞 시점
		gluLookAt(0.1, zoom, 0.1, 0.1, 0.0, 0.0, 0.0, 1.0, 0.0);
		break;
	case 4: // 무작위 시점
		gluLookAt(0.5, 0.5, zoom, 0.1, 0.0, 0.0, 1.0, 1.5, 0.0);
		break;
	default:
		gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.5, 0.0);
		break;
	}

	glColor3f(1.0, 0.3, 0.3); // 태양의 색깔
	glutWireSphere((1.0) / 4, 20, 16); // 태양 그리기

	glPushMatrix();
	glRotatef((GLfloat)Day4, 0.0, 1.0, 0.0);
	glTranslatef(0.45, 0.0, 0.0); // 태양으로부터의 거리: 수성
	glColor3f(R4, G4, B4); // 수성의 색깔
	glutWireSphere((0.1) / 4, 10, 8); // 수성 그리기
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat)Day2, 0.0, 1.0, 0.0);
	glTranslatef(0.6, 0.0, 0.0); // 태양으로부터의 거리: 금성
	glColor3f(R2, G2, B2); // 금성의 색깔
	glutWireSphere((0.25) / 4, 10, 8); // 금성 그리기
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat)Day3, 0.0, 1.0, 0.0);
	glTranslatef(1.0, 0.0, 0.0); // 태양으로부터의 거리: 지구
	glColor3f(R3, G3, B3); // 지구의 색깔
	glutWireSphere((0.25) / 4, 10, 8); // 지구 그리기

	glPushMatrix();
	glRotatef((GLfloat)Day6, 0.0, 1.0, 0.0);
	glTranslatef(0.2, 0.0, 0.0); // 지구로부터의 거리: 달
	glColor3f(R6, G6, B6); // 달의 색깔
	glutWireSphere((0.06) / 4, 10, 8); // 달 그리기
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat)Day5, 0.0, 1.0, 0.0);
	glTranslatef(1.35, 0.0, 0.0); // 태양으로부터의 거리: 화성
	glColor3f(R5, G5, B5); // 화성의 색깔
	glutWireSphere((0.125) / 4, 10, 8); // 화성 그리기
	glPopMatrix();


	glPushMatrix();
	glRotatef((GLfloat)Day7, 0.0, 1.0, 0.0);
	glTranslatef(1.55, 0.0, 0.0); // 태양으로부터의 거리: 목성
	glColor3f(R7, G7, B7); // 목성의 색깔
	glutWireSphere((0.4) / 4, 10, 8); // 목성 그리기
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat)Day8, 0.0, 1.0, 0.0);
	glTranslatef(1.85, 0.0, 0.0); // 태양으로부터의 거리: 토성
	glColor3f(R8, G8, B8); // 토성의 색깔
	glutWireSphere((0.3) / 4, 10, 8); // 토성 그리기
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat)Day9, 0.0, 1.0, 0.0);
	glTranslatef(2.15, 0.0, 0.0); // 태양으로부터의 거리: 천왕성
	glColor3f(R9, G9, B9); // 천왕성의 색깔
	glutWireSphere((0.16) / 4, 10, 8); // 천왕성 그리기
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat)Day10, 0.0, 1.0, 0.0);
	glTranslatef(2.45, 0.0, 0.0); // 태양으로부터의 거리: 혜왕성
	glColor3f(R10, G10, B10); // 혜왕성의 색깔
	glutWireSphere((0.15) / 4, 10, 8); // 혜왕성 그리기
	glPopMatrix();

	glutSwapBuffers();

}

void MyTimer(int Value)
{
	if (!isPaused) {
		Day2 = (Day2 + 16) % 360;  // 금성: 0.6 지구 년에 1회전
		Day3 = (Day3 + 10) % 360;  // 지구: 1 지구 년에 1회전
		Day4 = (Day4 + 25) % 360;  // 수성: 0.25 지구 년에 1회전
		Day5 = (Day5 + 2) % 360;  // 화성: 1.9 지구 년에 1회전
		Day6 = (Day6 + 70) % 360;  // 달: 0.07 지구 년에 1회전
		Day7 = (Day7 + 7) % 360;  // 목성: 1.2 지구 년에 1회전
		Day8 = (Day8 + 6) % 360;  // 토성: 1.2 지구 년에 1회전
		Day9 = (Day9 + 5) % 360;  // 천왕성: 1.1 지구 년에 1회전
		Day10 = (Day10 + 4) % 360;  // 혜왕성: 1.1 지구 년에 1회전
	}
	//일시 정지
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
	glutPostRedisplay();         // MyDisplay를 다시 호출한다.
	glutTimerFunc(speed, MyTimer, 1);       // 타이머콜백을 다시 호출한다.
}

void MyKeyboard(unsigned char key, int x, int y)
{
	switch (key) {
		// +키를 입력 받으면 속도 증가
	case '+':
		speed -= 10;  // 호출 간격을 더 짧게하여 속도 증가
		if (speed < 10)
			speed = 10;  // 최소 호출 간격 제한
		glutTimerFunc(speed, MyTimer, 1);  // 타이머 호출 간격 변경
		break;
		// -키를 입력 받으면 속도 감소
	case '-':
		speed += 10;  // 호출 간격을 더 길게하여 속도 감소
		if (speed > 160)
			speed = 160;  // 최대 호출 간격 제한
		glutTimerFunc(speed, MyTimer, 1);  // 타이머 호출 간격 변경
		break;
		// 스페이스 바를 입력 받으면 일시정지
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
	case GLUT_KEY_UP: // 위 화살표 키: 줌인
		zoom += 0.1;
		break;
	case GLUT_KEY_DOWN: // 아래 화살표 키: 줌아웃
		zoom -= 0.1;
		break;
	case GLUT_KEY_LEFT: // 왼쪽 화살표 키: 왼쪽 회전
		rotation -= 5.0f;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT: // 오른쪽 화살표 키: 오른쪽 회전
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
		glutSetWindowTitle("기본 시점");
		viewMode = 0;
		break;
	case 2:
		glutSetWindowTitle("위 시점");
		viewMode = 1;
		break;
	case 3:
		glutSetWindowTitle("옆 시점");
		viewMode = 2;
		break;
	case 4:
		glutSetWindowTitle("앞 시점");
		viewMode = 3;
		glutPostRedisplay();
		break;
	case 5:
		glutSetWindowTitle("무작위 시점");
		viewMode = rand() % 4;							//랜덤 시점 무작위로 0~3범위에서 변수 생성
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
	glutCreateWindow("20194022_김태완_TermProject");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.5, 2.5, -2.5, 2.5, -2.5, 2.5);

	glutCreateMenu(popupMenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddMenuEntry("기본 시점", 1);
	glutAddMenuEntry("위 시점", 2);
	glutAddMenuEntry("옆 시점", 3);
	glutAddMenuEntry("앞 시점", 4);
	glutAddMenuEntry("무작위 시점", 5);


	glutDisplayFunc(MyDisplay);
	glutTimerFunc(speed, MyTimer, 1);
	glutMouseFunc(mouse);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(SpecialInput);
	glutMainLoop();
	return 0;
}