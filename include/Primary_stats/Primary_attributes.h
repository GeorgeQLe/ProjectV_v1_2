/*  Copyright 2017 George Le
    Declaration of the Primary_stats class and its member function
*/
#ifndef PRIMARY_ATTRIBUTE_H
#define PRIMARY_ATTRIBUTE_H

enum Primary_attribute { NONE, STRENGTH, LEADERSHIP, INTELLIGENCE, CHARACTER, ENDURANCE};

class Primary_attributes
{
	public:
	Primary_attributes();
	Primary_attributes(int strength, int leadership, int intelligence, int character, int endurance);
	
	//bounds check mutator function
	void modify_stat(Primary_attribute to_be_Modified, int new_value);
	
	int strength() const { return m_strength; }
	int leadership() const { return m_leadership; }
	int intelligence() const { return m_intelligence; }
	int character() const { return m_character; }
	int endurance() const { return m_endurance; }
	
	private:
	int m_strength;
	int m_leadership;
	int m_intelligence;
	int m_character;
	int m_endurance;
};

#endif