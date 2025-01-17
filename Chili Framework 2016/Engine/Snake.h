#pragma once
#include "Board.h"
class Snake {
private:
	class Segment {
	public:
		void InitHead(const Location& loc);
		void InitBody();
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd)const;
		Location GetLocation();
		void setLocation(const Location& newLocation);
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	void Grow();
	void Draw( Board& brd) const;
	Location GetHeadLocation();
	void Reset(const Location& start);
	void Update(const Board& brd);
	bool alive = true;

private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
	bool hitWall = false;
	bool hitSelf = false;
	bool eatFruit = false;
};

