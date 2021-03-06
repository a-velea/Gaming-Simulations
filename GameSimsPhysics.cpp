#include "GameSimsPhysics.h"
#include "RigidBody.h"
#include "CollisionVolume.h"
#include "../../Common/Vector2.h"

using namespace NCL;
using namespace CSC3222;

GameSimsPhysics::GameSimsPhysics()	{

}

GameSimsPhysics::~GameSimsPhysics()	{

}

void GameSimsPhysics::Update(float dt) {
	Integration(dt);
	IntegrateVelocity(dt);
	for (auto it : allBodies) {
		it->force = Vector2(0, 0);
	}
	CollisionDetection(dt);
}

void GameSimsPhysics::AddRigidBody(RigidBody* b) {
	allBodies.emplace_back(b);
}

void GameSimsPhysics::RemoveRigidBody(RigidBody* b) {
	auto at = std::find(allBodies.begin(), allBodies.end(), b);

	if (at != allBodies.end()) {
		//maybe delete too?
		allBodies.erase(at);
	}
}

void GameSimsPhysics::AddCollider(CollisionVolume* c) {
	allColliders.emplace_back(c);
}

void GameSimsPhysics::RemoveCollider(CollisionVolume* c) {
	auto at = std::find(allColliders.begin(), allColliders.end(), c);

	if (at != allColliders.end()) {
		//maybe delete too?
		allColliders.erase(at);
	}
}

void GameSimsPhysics::Integration(float dt) {
	for (int i = 0;i < allBodies.size();i++) {
		Vector2 accelleration = allBodies[i]->force * allBodies[i]->inverseMass;
		allBodies[i]->velocity += accelleration * dt;
		allBodies[i]->velocity *= 0.85f;


	}
}

void GameSimsPhysics:: IntegrateVelocity(float dt) {
	for (int i = 0;i < allBodies.size();i++) {
		allBodies[i]->position += allBodies[i]->velocity * dt;
		allBodies[i]->force = Vector2(0, 0);
	}
}

void GameSimsPhysics::CollisionDetection(float dt) {

}