#pragma once
struct Location {

	int row;
	int col;
    Location& operator=(const Location& loc) 
    {
        row = loc.row;
        col = loc.col;
        return *this;
    }
        bool operator==(const Location & loc)
        {
            if(loc.row==this->row && loc.col == this->col)
            return true;
            return false;
        }
    
};