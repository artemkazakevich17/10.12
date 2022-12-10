#include "setting.h"
using namespace sf;
int main() {
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//�������� �������� ����
	//�������
	RectangleShape leftBat, rightBat;
	leftBat.setSize(batSize);
	rightBat.setSize(batSize);
	leftBat.setFillColor(leftBatColor);
	rightBat.setFillColor(rightBatColor);
	leftBat.setPosition(batOffset, (WINDOW_HEIGHT - batHeight) / 2);
	rightBat.setPosition(WINDOW_WIDTH - batOffset, (WINDOW_HEIGHT - batHeight) / 2);
	//�����
	CircleShape ball(ballRadius);
	ball.setFillColor(ballColor);
	ball.setPosition((WINDOW_WIDTH - 2 * ballRadius) / 2,
	(WINDOW_HEIGHT - 2 * ballRadius) / 2);

	float arr_speed[]{ -5.f, -4.f, -3.f, -2.f, -1.f, 1.f, 2.f, 3.f, 4.f, 5.f };
	float index = rand() % 10;
	float ball_speedx = arr_speed[index];
	index = rand() % 10;
	float ball_speedy = arr_speed[index];
	// C���
	int leftPlayerScore = 0;
	int rightPlayerScore = 0;
	Font font;
	font.loadFromFile("ds-digib.ttf");
	Text leftPlayerScoreText;
	leftPlayerScoreText.setString(std::to_string(leftPlayerScore)); //�������� ������� ��� �����������
	leftPlayerScoreText.setFont(font);
	leftPlayerScoreText.setCharacterSize(64);
	leftPlayerScoreText.setPosition(200.f, 10.f);

	Text rightPlayerScoreText;
	rightPlayerScoreText.setString(std::to_string(rightPlayerScore));
	rightPlayerScoreText.setFont(font);
	rightPlayerScoreText.setCharacterSize(64);
	rightPlayerScoreText.setPosition(550.f, 10.f)


	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		//1 ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
			{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
			// ����� ��������� ���
			window.close();
			}
		//2 ���������� ��������
		//�����
		//�������� ������
		ball.move(ball_speedx, ball_speedy);
		//�����-����� �� �����
		if (ball.getPosition().x <= 0)
		{
			// �������� ��� x ��������� �� ���������������
			ball_speedx = -ball_speedx;
			// ������ ����� ����� ���
			rightPlayerScore++;
		}
		//��� ������ �������

		if (ball.getPosition().x >= (WINDOW_WIDTH - 2 * ballRadius))
		{
			//��������� �� ��� X ��������� �� ���������������
			ball_speedx = -ball_speedx;
			leftPlayerScore++;
		}
		//�������� ������� ������
		//���� ������� W ������
		if (Keybord::isKeyPressed(Keybord::W)) {
			leftBatSpeedY = -batSpeed;
		}
		if (Keybord::isKeyPressed(Keybord::S)) {
			leftBatSpeedY = batSpeed;
		}
		//������� �������
		leftBat.move(0, leftBatSpeedY);
		// � ����� �� �������� ��������
		leftBatSpeedY = 0;

		if (Keybord::isKeyPressed(Keybord::Up)) {
			rightBatSpeedY = -batSpeed;
		}
		if (Keybord::isKeyPressed(Keybord::Down)) {
			rightBatSpeedY = batSpeed;
		}


		//3 ��������� ����
		//3.1 ������� ����
		window.clear()
			//3.2 ��������� �������� (� ������!)
			window.draw(leftBat)
			window.draw(rightBat)
			window.draw(ball)
			window.draw(leftPlayerText);
		//3.3 ����� �� �����
		window.display()


		return 0;
}
