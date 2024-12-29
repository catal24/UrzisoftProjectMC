﻿#include "Game.h"


Game::Game( Difficulty difficulty)
	:m_scene{ new GameScene{randomMap()}}, m_playerCount{1}, m_difficulty{difficulty}
{
	m_v = { m_v.GetStartingPositions()[m_playerCount - 1].first,
		m_v.GetStartingPositions()[m_playerCount - 1].second,0,false,true,3,5,false,Axis::down };
	m_scene->AddObj(&m_v);
}


void Game::startGame()
{
	// Start the game
	isStart = true;
	std::queue<GameObject*> q;
	m_scene->DrawTest(*this);

	// Assuming there's an app already set up for Crow (as you've shown previously)
	crow::SimpleApp app;

	// Route to send the map as JSON
	CROW_ROUTE(app, "/map")([&]() {
		// Generate the map encoding (toSend) and send it as JSON
		std::string toSend = m_scene->GetMap().EncodeMap2();
		return crow::json::wvalue({ {"map", toSend} });
		});

	// Run the Crow app in a separate thread to keep it non-blocking
	std::thread appThread([&app]() {
		app.port(18080).multithreaded().run();
		});

	while (isStart) {
		// Sleep to control game speed
		Sleep(50);

		// Handle input and update game state
		InputControll();
		BulletMoving();

		// Optionally, update the map or game state to reflect any changes
		std::string toSend = m_scene->GetMap().EncodeMap2();

		// You could handle any other game-related operations here, like sending the updated data
	}

	std::cout << "GameOver\n";

	// Ensure the app thread joins before finishing the game loop
	appThread.join();
}

void Game::InputControll()
{
	// Controlul jucătorului
	if (_kbhit() && !m_v.GetIsDead()) {
		char key = _getch();
		if (key == 'w' || key == 'W') {
			m_scene->MoveObject(&m_v, m_v.GetXStart() - 1, m_v.GetYStart());
			m_v.SetAxis(key);

		}
		else if (key == 's' || key == 'S') {
			m_scene->MoveObject(&m_v, m_v.GetXStart() + 1, m_v.GetYStart());
			m_v.SetAxis(key);

		}
		else if (key == 'a' || key == 'A') {
			m_scene->MoveObject(&m_v, m_v.GetXStart(), m_v.GetYStart() - 1);
			m_v.SetAxis(key);

		}
		else if (key == 'd' || key == 'D') {
			m_scene->MoveObject(&m_v, m_v.GetXStart(), m_v.GetYStart() + 1);
			m_v.SetAxis(key);

		}
		else if (key == ' ') {
			Shoot();
		}
	}
}

Map& Game::GetMap()
{
	return m_map;
}

GameScene* Game::GetScene()
{
	return m_scene;
}



std::vector<std::vector<int>> Game::randomMap()
{
	std::random_device rd;

	std::mt19937 gen(rd());

	std::uniform_int_distribution<> dist(1, 10);

	int random_number = dist(gen);

	 std::string fileName;
    switch (random_number) {
        case 1:
            fileName = "Map1.txt";
            break;
        case 2:
            fileName = "Map2.txt";
            break;
        case 3:
            fileName = "Map3.txt";
            break;
        case 4:
            fileName = "Map4.txt";
            break;
        case 5:
            fileName = "Map5.txt";
            break;
		case 6:
			fileName = "Map6.txt";
			break;
		case 7:
			fileName = "Map7.txt";
			break;
		case 8:
			fileName = "Map8.txt";
			break;
		case 9:
			fileName = "Map9.txt";
			break;
		case 10:
			fileName = "Map10.txt";
			break;

    }

	std::ifstream inputFile(fileName);



	std::vector<std::vector<int>> map;
	map.resize(20);
	if (!inputFile) {
		std::cerr << "Nu s-a putut deschide fișierul!" << std::endl;
		
	}
	for (int i = 0; i < 20; ++i) {
		map[i].resize(20);
		for (int j = 0; j < 20; ++j) {
			inputFile >> map[i][j];
			
		}
	}

	inputFile.close();
	return map;
}

void Game::Shoot() {
	static unsigned long lastShotTime = 0;  // Timpul ultimei trageri
	const unsigned long shootDelay = 500;  // Delay de 500ms între trageri
	unsigned long currentTime = GetTickCount();

	// Verificăm dacă putem trage
	if (currentTime - lastShotTime < shootDelay) {
		return;  // Ieșim dacă nu a trecut suficient timp
	}

	// Coordonatele vehiculului curent
	int currentX = m_v.GetXStart();
	int currentY = m_v.GetYStart();

	// Coordonatele țintei în funcție de direcția vehiculului
	int targetX = currentX;
	int targetY = currentY;

	switch (m_v.GetAxis()) {
	case Axis::up:    targetX--; break;
	case Axis::down:  targetX++; break;
	case Axis::left:  targetY--; break;
	case Axis::right: targetY++; break;
	}

	// Verificăm dacă la poziția țintă se află un perete indestructibil
	GameObject* targetObj = m_scene->GetObjectAt(targetX, targetY);
	if (Wall* wall = dynamic_cast<Wall*>(targetObj)) {
		if (!wall->IsBreakable()) {
			return;  // Ieșim dacă nu putem trage în perete
		}
	}

	// Creăm un glonț nou și îl adăugăm în lista de gloanțe
	auto newBullet = m_v.ShootBullet(currentX, currentY);
	bullets.push_back(std::move(newBullet));

	// Actualizăm timpul ultimei trageri
	lastShotTime = currentTime;
}


void Game::BulletMoving() {
	// Iterate through bullets
	for (auto it = bullets.begin(); it != bullets.end();) {
		auto bullet = it->get();
		int newX = bullet->GetXStart();
		int newY = bullet->GetYStart();

		// Determine new position based on direction
		if (!bullet->IsFirstMove()) {
			switch (bullet->GetAxis()) {
			case Axis::up:    newX--; break;
			case Axis::down:  newX++; break;
			case Axis::left:  newY--; break;
			case Axis::right: newY++; break;
			}
		}
		else {
			bullet->SetFirstMove(false);
		}

		// Check collision at the new position
		if (m_scene->CheckObj(newX, newY)) {
			// Move the bullet if no collision occurs
			m_scene->MoveObject(bullet, newX, newY);
			bullet->SetXStart(newX);
			bullet->SetYStart(newY);
			++it;  // Advance the iterator
		}
		else {
			// Handle collision and update iterator
			HandleBulletCollision(it, newX, newY);
		}
	}
}


Game::Difficulty Game::GetDifficulty() { return m_difficulty; }
void Game::SetDifficulty(Difficulty difficulty) { m_difficulty = difficulty; }

void Game::HandleBombCollision(Bomb* bomb, int bombX, int bombY)
{
	//vector de perechi pentru directii
	std::vector<std::pair<int, int>> directions = {
		{-1,0},// sus
		{-1,1},//dreapta sus
		{0,1},//dreapta
		{1,1},//dreapta jos
		{1,0},//jos
		{1,-1},//stanga jos
		{0,-1},//stanga
		{-1,-1}//stanga sus
	};
	for (const auto& dir : directions)
	{
		int checkX = bombX + dir.first;
		int checkY = bombY + dir.second;
		//verificam daca este perete destructibil langa bomba
		if (Wall* wall = dynamic_cast<Wall*>(m_scene->GetObjectAt(checkX, checkY)))
		{
			if (wall->IsBreakable())
				m_scene->RemoveObj(checkX, checkY);
		}
		//verificam daca este vehicul si il distrugem
		if (Vehicle* vehicle = dynamic_cast<Vehicle*>(m_scene->GetObjectAt(checkX, checkY))) {
			m_scene->RespawnObj(vehicle, 1, 1);
			if (vehicle->GetLives() == 0)
			{
				isStart = false;
				system("cls");
			}
			//m_scene->removeObj(checkX, checkY);
		}
		//distrugem si bombele
		if (Bomb* bomb = dynamic_cast<Bomb*>(m_scene->GetObjectAt(checkX, checkY))) {
			m_scene->RemoveObj(checkX, checkY);
		}
	}
}

void Game::HandleBulletCollision(std::vector<std::shared_ptr<Bullet>>::iterator& it, int newX, int newY) {
	Bullet* bullet = it->get();

	// Dacă lovește un tanc
	if (Vehicle* vehicle = dynamic_cast<Vehicle*>(m_scene->GetObjectAt(newX, newY))) {
		// Respawn the vehicle
		m_scene->RespawnObj(vehicle, 1, 1); 
		m_scene->RemoveObj(newX, newY);                  
		m_scene->RemoveObj(bullet->GetXStart(), bullet->GetYStart()); 
		
		it = bullets.erase(it);
		if (vehicle->GetLives() == 0)
			isStart = false;
		return;
	}


	// Dacă lovește un alt glonț
	if (dynamic_cast<Bullet*>(m_scene->GetObjectAt(newX, newY))) {
		m_scene->RemoveObj(newX, newY);
		m_scene->RemoveObj(bullet->GetXStart(), bullet->GetYStart());
		it = bullets.erase(it);  // Ștergem și actualizăm iteratorul
		return;
	}

	// Dacă lovește un perete
	if (Wall* wall = dynamic_cast<Wall*>(m_scene->GetObjectAt(newX, newY))) {
		if (wall->IsBreakable()) {
			m_scene->RemoveObj(newX, newY);
		}
		m_scene->RemoveObj(bullet->GetXStart(), bullet->GetYStart());
		it = bullets.erase(it);  // Ștergem și actualizăm iteratorul
		return;
	}

	// Dacă lovește o bombă
	if (Bomb* bomb = dynamic_cast<Bomb*>(m_scene->GetObjectAt(newX, newY))) {
		HandleBombCollision(bomb, newX, newY);
		m_scene->RemoveObj(newX, newY);
		m_scene->RemoveObj(bullet->GetXStart(), bullet->GetYStart());
		it = bullets.erase(it);  // Ștergem și actualizăm iteratorul
		return;
	}

	// Dacă nu se întâmplă nimic, doar avansăm iteratorul
	++it;
}



