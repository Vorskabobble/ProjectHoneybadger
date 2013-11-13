#include "Chunk.h"
#include <iostream>

Chunk::Chunk(Zone* zones, Tile* solids)
{
	m_solids = solids;
	m_zones = zones;
}


Chunk::~Chunk(void)
{
	if(m_solids != NULL){
		delete[] m_solids;
	}
	if(m_zones != NULL){
		delete[] m_zones;
	}
}

Tile* Chunk::solidTiles(void)
{
	return m_solids;
}


Zone* Chunk::zones(void)
{
	return m_zones;
}
