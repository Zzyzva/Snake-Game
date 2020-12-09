#include "EnemyShip_BattleMap_EH.h"

EnemyShip_BattleMap_EH::EnemyShip_BattleMap_EH( Scene* scene, EnemyShip_BattleMap_GO* self ) {
    this->scene = scene;
    this->self = self;
    
    scene->eventManager->registerHandler( "SpacePressed", this );
    scene->eventManager->registerHandler( "EnemyShip_BattleMap_Move", this );
}

void EnemyShip_BattleMap_EH::handleEvent( Event* e ) {
    if( e->getName().compare( "SpacePressed" ) == 0 ) {
        if( self->angle >= 180 ) {
            self->angle = self->angle - 180;
        }
        else {
            self->angle = self->angle + 180;
        }
    }
    else if( e->getName().compare("EnemyShip_BattleMap_Move") == 0 ) {
        float x = 0;
        float y = 0;
        std::vector<Variant*>* list = e->getParams();
        for ( Variant* v : *list ) {
            if ( v->name.compare( "x" ) == 0 ) {
                x = v->f;
            }
            else if ( v->name.compare( "y" ) == 0 ) {
                y = v->f;
            }
        }
        self->collider->setPosition( x, y );
    }
}