#pragma once
#include "SimObject.h"

namespace NCL {
	
	namespace Maths {
		class Vector2;
	}
	namespace CSC3222 {
		class Spell : public SimObject {
		public:
			Spell(Vector2 direction);
			~Spell();
			float timeSpawned;
			Vector2 direction;
			void DrawObject(GameSimsRenderer &r) override;
			bool UpdateObject(float dt) override;
		};
	}
}

