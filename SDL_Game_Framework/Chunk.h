#pragma once

class Zone;
class Tile;

class Chunk{
private:
	int m_x, m_y;
	Zone* m_zones;
	Tile* m_solids;
public:
	Chunk(Zone* zones, Tile* solids);
	~Chunk(void);

	int X();
	int Y();

	Tile* solidTiles(void);
	Zone* zones(void);
};

