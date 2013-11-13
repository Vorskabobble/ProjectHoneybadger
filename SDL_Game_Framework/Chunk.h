#pragma once

class Zone;
class Tile;

class Chunk{
private:
	Zone* m_zones;
	Tile* m_solids;
public:
	Chunk(Zone* zones, Tile* solids);
	~Chunk(void);

	Tile* solidTiles(void);
	Zone* zones(void);
};

