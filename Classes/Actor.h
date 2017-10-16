#pragma once
#include "cocos2d.h"

#ifdef WIN32
#include <json/json.h>
#else
#include "json.h"
#endif



class Actor : public cocos2d::Sprite
{

public:
	typedef std::function<void()> AttackCallBack;

	enum CombatStatus {
		UNPREPARED = 0,
		PREPARED = 1,
		ON_ATTACK = 2,
	};
	virtual bool init();
	CREATE_FUNC(Actor);

	static Actor* createActor(int index);

	AttackCallBack userAction;
	AttackCallBack deadAction;

	void idle();
	void dead();
	void defend();
	void stand(int type);
	void suffer(float time);
	void walk(cocos2d::Vec2 target, bool canMove);
	void attack(Actor* target, int type);

	void setBlood(int blood) { _blood = blood; }
	int getBlood() const { return _blood; }

	void setSpeed(float speed) { _speed = speed; }
	float getSpeed() const { return _speed; }

	void setStatus(CombatStatus status) { _status = status; }
	CombatStatus getStatus() const{ return _status; }

	void setCombatPos(int combatPos) { _combatPos = combatPos; }
	int getCombatPos() const { return _combatPos; }

	void setBloodBarDisplay(bool show);
	void updateBloodBarValue();
	void showDamageValues();


private:
	//meta
	int _id;
	int _combatPos;

	int _blood;
	float _speed;

	std::string _name;
	std::string _path;
	Json::Value _anim;

	CombatStatus _status;//0 δ׼�� 1��׼�� 2ʩ���� 

};
