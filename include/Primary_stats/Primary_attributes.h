/*  Copyright 2017 George Le
    Declaration of the Primary_stats class and its member function
*/
#ifndef PRIMARY_ATTRIBUTE_H
#define PRIMARY_ATTRIBUTE_H

enum Primary_attribute { NONE, STRENGTH, LEADERSHIP, INTELLIGENCE, CHARACTER, ENDURANCE};

class CPrimaryAttributes
{
	public:
	CPrimaryAttributes();
	CPrimaryAttributes(int strength, int leadership, int intelligence, int character, int endurance);
	
	//bounds check mutator function
	void ModifyStat(Primary_attribute to_be_Modified, int new_value);
	
	int Strength() const { return m_strength; }
	int Leadership() const { return m_leadership; }
	int Intelligence() const { return m_intelligence; }
	int Character() const { return m_character; }
	int Endurance() const { return m_endurance; }
	
	private:
	int m_strength;
	int m_leadership;
	int m_intelligence;
	int m_character;
	int m_endurance;
};

#endif