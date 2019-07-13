

class AirBlock : public Block
{
	public:
	
	AirBlock(int x, int y, int z) : Block(x,y,z)
	{
	}
	
	virtual bool isAir() {return true;}
	virtual bool IsSeeAtMe(float cX,float cY,float cZ, float rX,float rY, float rZ, float* len, int* side)
	{
		
		return false;
		}
	};
