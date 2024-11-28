#include "Game.h"


Game::Game(std::vector<std::vector<int>> m_initMap, Difficulty difficulty)
	:m_scene{ new GameScene{m_initMap} }, m_playerCount{ 1 }, m_difficulty{ difficulty }
{
	m_v = { m_v.GetStartingPositions()[m_playerCount - 1].first,
		m_v.GetStartingPositions()[m_playerCount - 1].second,0,false,true,3,5,false,Axis::down };
	m_scene->AddObj(&m_v);
}
//spawn the vehicle at a dafault location
void Game::startGame()
{
	bool isStart = true;
	std::queue<GameObject*> q;
	m_scene->DrawTest(*this);

	unsigned long lastShotTime = 0;  // Timpul ultimei trageri
	const unsigned long shootDelay = 500; // Delay de 500ms între trageri

	while (isStart) {
		Sleep(50);  // Sleep pentru a controla viteza jocului

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
				unsigned long currentTime = GetTickCount();
				if (currentTime - lastShotTime >= shootDelay) {

					// coord vehiculului curent
					int currentX = m_v.GetXStart();
					int currentY = m_v.GetYStart();

					// coord tintei in functie de directia vehiculului
					int targetX = currentX;
					int targetY = currentY;

					switch (m_v.GetAxis()) {
					case Axis::up:    targetX--; break;   // verif sus jos stanga dreapta
					case Axis::down:  targetX++; break;
					case Axis::left:  targetY--; break;
					case Axis::right: targetY++; break;
					}

					// verificam daca la pozitia tinta se afla un `Wall` indestructibil
					GameObject* targetObj = m_scene->GetObjectAt(targetX, targetY);
					if (Wall* wall = dynamic_cast<Wall*>(targetObj)) {
						if (!wall->IsBreakable()) {
							continue;  // sarim peste actiunea de tragere
						}
					}

					auto newBullet = m_v.ShootBullet(m_v.GetX(), m_v.GetY());
					bullets.push_back(std::move(newBullet));
					lastShotTime = currentTime; // actualizam timpul ultimei trageri
				}
			}
		}

		// miscarea gloantelor
		for (auto it = bullets.begin(); it != bullets.end();) {
			auto bullet = *it;
			int newX = (*it)->GetXStart();
			int newY = (*it)->GetYStart();

			if (!(*it)->IsFirstMove())
			{
				// Determinăm direcția glonțului
				switch ((*it)->GetAxis()) {
				case Axis::up:    newX--; break;
				case Axis::down:  newX++; break;
				case Axis::left:  newY--; break;
				case Axis::right: newY++; break;
				}
			}
			else {
				(*it)->SetFirstMove(false);
			}

			// Verificăm coliziunea
			if (m_scene->CheckObj(newX, newY)) {
				// Dacă nu lovește nimic, mutăm glonțul
				m_scene->MoveObject((*it).get(), newX, newY);
				(*it)->SetXStart(newX); // Actualizăm poziția glonțului
				(*it)->SetYStart(newY);
				++it; // Avansăm iteratorul
			}
			else {
				// Dacă există coliziune, gestionăm și actualizăm iteratorul
				HandleBulletCollision(it, newX, newY);
			}
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



