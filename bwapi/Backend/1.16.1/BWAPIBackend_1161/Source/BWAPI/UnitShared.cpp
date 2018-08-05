#include <BWAPI.h>
#include <BWAPI/Client/UnitData.h>
#include "UnitImpl.h"
#include <Templates.h>
#include "GameImpl.h"

namespace BWAPI
{
  //--------------------------------------------- CLEAR ------------------------------------------------------
  void UnitImpl::clear()
  {
    initialType      = UnitTypes::None;
    initialResources = 0;
    initialHitPoints = 0;
    initialPosition  = Positions::None;
    lastCommandFrame = 0;
    lastCommand      = UnitCommand();
    this->clientInfo.clear();
    this->interfaceEvents.clear();

    connectedUnits.clear();
  }
  //------------------------------------- INITIAL INFORMATION FUNCTIONS --------------------------------------
  void UnitImpl::saveInitialState()
  {
    initialType      = getType();
    initialPosition  = getPosition();
    initialResources = getResources();
    initialHitPoints = getHitPoints();
  }
  //--------------------------------------------- GET ID -----------------------------------------------------
  int UnitImpl::getID() const
  {
    return id;
  }
  //--------------------------------------------- GET REPLAY ID ----------------------------------------------
  int UnitImpl::getReplayID() const
  {
    return data.replayID;
  }
  //--------------------------------------------- GET PLAYER -------------------------------------------------
  Player UnitImpl::getPlayer() const
  {
    return getGame().getPlayer(data.player);
  }
  //--------------------------------------------- GET TYPE ---------------------------------------------------
  UnitType UnitImpl::getType() const
  {
    return UnitType(data.type);
  }
  //--------------------------------------------- GET POSITION -----------------------------------------------
  Position UnitImpl::getPosition() const
  {
    return Position(data.positionX, data.positionY);
  }
  //--------------------------------------------- GET ANGLE --------------------------------------------------
  double UnitImpl::getAngle() const
  {
    return data.angle;
  }
  //--------------------------------------------- GET VELOCITY X ---------------------------------------------
  double UnitImpl::getVelocityX() const
  {
    return data.velocityX;
  }
  //--------------------------------------------- GET VELOCITY Y ---------------------------------------------
  double UnitImpl::getVelocityY() const
  {
    return data.velocityY;
  }
  //--------------------------------------------- GET HIT POINTS ---------------------------------------------
  int UnitImpl::getHitPoints() const
  {
    return data.hitPoints;
  }
  //--------------------------------------------- GET SHIELDS ------------------------------------------------
  int UnitImpl::getShields() const
  {
    return data.shields;
  }
  //--------------------------------------------- GET ENERGY -------------------------------------------------
  int UnitImpl::getEnergy() const
  {
    return data.energy;
  }
  //--------------------------------------------- GET RESOURCES ----------------------------------------------
  int UnitImpl::getResources() const
  {
    return data.resources;
  }
  //--------------------------------------------- GET RESOURCE GROUP -----------------------------------------
  int UnitImpl::getResourceGroup() const
  {
    return data.resourceGroup;
  }
  //--------------------------------------------- GET LAST COMMAND FRAME -------------------------------------
  int UnitImpl::getLastCommandFrame() const
  {
    return lastCommandFrame;
  }
  //--------------------------------------------- GET LAST COMMAND -------------------------------------------
  UnitCommand UnitImpl::getLastCommand() const
  {
    return lastCommand;
  }
  //--------------------------------------------- GET LAST ATTACKING PLAYER ----------------------------------
  BWAPI::Player UnitImpl::getLastAttackingPlayer() const
  {
    return BroodwarImpl.getPlayer(data.lastAttackerPlayer);
  }
  //--------------------------------------------- GET INITIAL TYPE -------------------------------------------
  UnitType UnitImpl::getInitialType() const
  {
    return initialType;
  }
  //--------------------------------------------- GET INITIAL POSITION ---------------------------------------
  Position UnitImpl::getInitialPosition() const
  {
    return initialPosition;
  }
  //--------------------------------------------- GET INITIAL TILE POSITION ----------------------------------
  TilePosition UnitImpl::getInitialTilePosition() const
  {
    if ( initialPosition == Positions::None )
      return TilePositions::None;
    return TilePosition(initialPosition - Position(initialType.tileSize())/2);
  }
  //--------------------------------------------- GET INITIAL HIT POINTS -------------------------------------
  int UnitImpl::getInitialHitPoints() const
  {
    return initialHitPoints;
  }
  //--------------------------------------------- GET INITIAL RESOURCES --------------------------------------
  int UnitImpl::getInitialResources() const
  {
    return initialResources;
  }
  //--------------------------------------------- GET KILL COUNT ---------------------------------------------
  int UnitImpl::getKillCount() const
  {
    return data.killCount;
  }
  //--------------------------------------------- GET ACID SPORE COUNT ---------------------------------------
  int UnitImpl::getAcidSporeCount() const
  {
    return data.acidSporeCount;
  }
  //--------------------------------------------- GET INTERCEPTOR COUNT --------------------------------------
  int UnitImpl::getInterceptorCount() const
  {
    return data.interceptorCount;
  }
  //--------------------------------------------- GET SCARAB COUNT -------------------------------------------
  int UnitImpl::getScarabCount() const
  {
    return data.scarabCount;
  }
  //--------------------------------------------- GET SPIDER MINE COUNT --------------------------------------
  int UnitImpl::getSpiderMineCount() const
  {
    return data.spiderMineCount;
  }
  //--------------------------------------------- GET GROUND WEAPON COOLDOWN ---------------------------------
  int UnitImpl::getGroundWeaponCooldown() const
  {
    return data.groundWeaponCooldown;
  }
  //--------------------------------------------- GET AIR WEAPON COOLDOWN ------------------------------------
  int UnitImpl::getAirWeaponCooldown() const
  {
    return data.airWeaponCooldown;
  }
  //--------------------------------------------- GET SPELL COOLDOWN -----------------------------------------
  int UnitImpl::getSpellCooldown() const
  {
    return data.spellCooldown;
  }
  //--------------------------------------------- GET DEFENSE MATRIX POINTS ----------------------------------
  int UnitImpl::getDefenseMatrixPoints() const
  {
    return data.defenseMatrixPoints;
  }
  //--------------------------------------------- GET DEFENSE MATRIX TIMER -----------------------------------
  int UnitImpl::getDefenseMatrixTimer() const
  {
    return data.defenseMatrixTimer;
  }
  //--------------------------------------------- GET ENSNARE TIMER ------------------------------------------
  int UnitImpl::getEnsnareTimer() const
  {
    return data.ensnareTimer;
  }
  //--------------------------------------------- GET IRRADIATE TIMER ----------------------------------------
  int UnitImpl::getIrradiateTimer() const
  {
    return data.irradiateTimer;
  }
  //--------------------------------------------- GET LOCKDOWN TIMER -----------------------------------------
  int UnitImpl::getLockdownTimer() const
  {
    return data.lockdownTimer;
  }
  //--------------------------------------------- GET MAELSTROM TIMER ----------------------------------------
  int UnitImpl::getMaelstromTimer() const
  {
    return data.maelstromTimer;
  }
  //--------------------------------------------- GET ORDER TIMER --------------------------------------------
  int UnitImpl::getOrderTimer() const
  {
    return data.orderTimer;
  }
  //--------------------------------------------- GET PLAGUE TIMER -------------------------------------------
  int UnitImpl::getPlagueTimer() const
  {
    return data.plagueTimer;
  }
  //--------------------------------------------- GET REMOVE TIMER -------------------------------------------
  int UnitImpl::getRemoveTimer() const
  {
    return data.removeTimer;
  }
  //--------------------------------------------- GET STASIS TIMER -------------------------------------------
  int UnitImpl::getStasisTimer() const
  {
    return data.stasisTimer;
  }
  //--------------------------------------------- GET STIM TIMER ---------------------------------------------
  int UnitImpl::getStimTimer() const
  {
    return data.stimTimer;
  }
  //--------------------------------------------- GET BUILD TYPE ---------------------------------------------
  UnitType UnitImpl::getBuildType() const
  {
    return UnitType(data.buildType);
  }
  //--------------------------------------------- GET TRAINING QUEUE -----------------------------------------
  UnitType::list UnitImpl::getTrainingQueue() const
  {
    return UnitType::list(std::begin(data.trainingQueue), std::begin(data.trainingQueue) + data.trainingQueueCount);
  }
  //--------------------------------------------- GET TECH ---------------------------------------------------
  TechType UnitImpl::getTech() const
  {
    return TechType(data.tech);
  }
  //--------------------------------------------- GET UPGRADE ------------------------------------------------
  UpgradeType UnitImpl::getUpgrade() const
  {
    return UpgradeType(data.upgrade);
  }
  //--------------------------------------------- GET REMAINING BUILD TIME -----------------------------------
  int UnitImpl::getRemainingBuildTime() const
  {
    return data.remainingBuildTime;
  }
  //--------------------------------------------- GET REMAINING TRAIN TIME -----------------------------------
  int UnitImpl::getRemainingTrainTime() const
  {
    return data.remainingTrainTime;
  }
  //--------------------------------------------- GET REMAINING RESEARCH TIME --------------------------------
  int UnitImpl::getRemainingResearchTime() const
  {
    return data.remainingResearchTime;
  }
  //--------------------------------------------- GET REMAINING UPGRADE TIME ---------------------------------
  int UnitImpl::getRemainingUpgradeTime() const
  {
    return data.remainingUpgradeTime;
  }
  //--------------------------------------------- GET BUILD UNIT ---------------------------------------------
  Unit UnitImpl::getBuildUnit() const
  {
    return BroodwarImpl.getUnit(data.buildUnit);
  }
  //--------------------------------------------- GET TARGET -------------------------------------------------
  Unit UnitImpl::getTarget() const
  {
    return BroodwarImpl.getUnit(data.target);
  }
  //--------------------------------------------- GET TARGET POSITION ----------------------------------------
  Position UnitImpl::getTargetPosition() const
  {
    return Position(data.targetPositionX,data.targetPositionY);
  }
  //--------------------------------------------- GET ORDER --------------------------------------------------
  Order UnitImpl::getOrder() const
  {
    return Order(data.order);
  }
  //--------------------------------------------- GET ORDER TARGET -------------------------------------------
  Unit UnitImpl::getOrderTarget() const
  {
    return BroodwarImpl.getUnit(data.orderTarget);
  }
  //--------------------------------------------- GET ORDER TARGET POSITION ----------------------------------
  Position UnitImpl::getOrderTargetPosition() const
  {
    return Position(data.orderTargetPositionX,data.orderTargetPositionY);
  }
  //--------------------------------------------- GET SECONDARY ORDER ID -------------------------------------
  Order UnitImpl::getSecondaryOrder() const
  {
    return Order(data.secondaryOrder);
  }
  //--------------------------------------------- GET RALLY POSITION -----------------------------------------
  Position UnitImpl::getRallyPosition() const
  {
    return Position(data.rallyPositionX,data.rallyPositionY);
  }
  //--------------------------------------------- GET RALLY UNIT ---------------------------------------------
  Unit UnitImpl::getRallyUnit() const
  {
    return BroodwarImpl.getUnit(data.rallyUnit);
  }
  //--------------------------------------------- GET ADDON --------------------------------------------------
  Unit UnitImpl::getAddon() const
  {
    return BroodwarImpl.getUnit(data.addon);
  }
  //--------------------------------------------- GET NYDUS EXIT ---------------------------------------------
  Unit UnitImpl::getNydusExit() const
  {
    return BroodwarImpl.getUnit(data.nydusExit);
  }
  //--------------------------------------------- GET POWER UP -----------------------------------------------
  Unit UnitImpl::getPowerUp() const
  {
    return BroodwarImpl.getUnit(data.powerUp);
  }
  //--------------------------------------------- GET TRANSPORT ----------------------------------------------
  Unit UnitImpl::getTransport() const
  {
    return BroodwarImpl.getUnit(data.transport);
  }
  //--------------------------------------------- GET LOADED UNITS -------------------------------------------
  Unitset UnitImpl::getLoadedUnits() const
  {
    return loadedUnits;
  }
  //--------------------------------------------- GET CARRIER ------------------------------------------------
  Unit UnitImpl::getCarrier() const
  {
    return BroodwarImpl.getUnit(data.carrier);
  }
  //--------------------------------------------- GET INTERCEPTORS -------------------------------------------
  Unitset UnitImpl::getInterceptors() const
  {
    if (getType() != UnitTypes::Protoss_Carrier && getType() != UnitTypes::Hero_Gantrithor)
      return Unitset{};
    return connectedUnits;
  }
  //--------------------------------------------- GET HATCHERY -----------------------------------------------
  Unit UnitImpl::getHatchery() const
  {
    return BroodwarImpl.getUnit(data.hatchery);
  }
  //--------------------------------------------- GET LARVA --------------------------------------------------
  Unitset UnitImpl::getLarva() const
  {
    if (!getType().producesLarva())
      return Unitset{};
    return connectedUnits;
  }
  //--------------------------------------------- EXISTS -----------------------------------------------------
  bool UnitImpl::exists() const
  {
    return data.exists;
  }
  //--------------------------------------------- HAS NUKE ---------------------------------------------------
  bool UnitImpl::hasNuke() const
  {
    return data.hasNuke;
  }
  //--------------------------------------------- IS ACCELERATING --------------------------------------------
  bool UnitImpl::isAccelerating() const
  {
    return data.isAccelerating;
  }
  //--------------------------------------------- IS ATTACKING -----------------------------------------------
  bool UnitImpl::isAttacking() const
  {
    return data.isAttacking;
  }
  //--------------------------------------------- IS ATTACK FRAME --------------------------------------------
  bool UnitImpl::isAttackFrame() const
  {
    return data.isAttackFrame;
  }
  //--------------------------------------------- IS BEING GATHERED ------------------------------------------
  bool UnitImpl::isBeingGathered() const
  {
    return data.isBeingGathered;
  }
  //--------------------------------------------- IS BEING HEALED --------------------------------------------
  bool UnitImpl::isBeingHealed() const
  {
    return getType().getRace() == Races::Terran &&
           data.isCompleted &&
           data.hitPoints > data.lastHitPoints;
  }
  //--------------------------------------------- IS BLIND ---------------------------------------------------
  bool UnitImpl::isBlind() const
  {
    return data.isBlind;
  }
  //--------------------------------------------- IS BRAKING -------------------------------------------------
  bool UnitImpl::isBraking() const
  {
    return data.isBraking;
  }
  //--------------------------------------------- IS BURROWED ------------------------------------------------
  bool UnitImpl::isBurrowed() const
  {
    return data.isBurrowed;
  }
  //--------------------------------------------- IS CARRYING GAS --------------------------------------------
  bool UnitImpl::isCarryingGas() const
  {
    return data.carryResourceType == 1;
  }
  //--------------------------------------------- IS CARRYING MINERALS ---------------------------------------
  bool UnitImpl::isCarryingMinerals() const
  {
    return data.carryResourceType == 2;
  }
  //--------------------------------------------- IS CLOAKED -------------------------------------------------
  bool UnitImpl::isCloaked() const
  {
    return data.isCloaked;
  }
  //--------------------------------------------- IS COMPLETED -----------------------------------------------
  bool UnitImpl::isCompleted() const
  {
    return data.isCompleted;
  }
  //--------------------------------------------- IS CONSTRUCTING --------------------------------------------
  bool UnitImpl::isConstructing() const
  {
    return data.isConstructing;
  }
  //--------------------------------------------- IS DETECTED ------------------------------------------------
  bool UnitImpl::isDetected() const
  {
    return data.isDetected;
  }
  //--------------------------------------------- IS GATHERING GAS -------------------------------------------
  bool UnitImpl::isGatheringGas() const
  {
    if (!data.isGathering)
      return false;

    if (data.order != Orders::Harvest1   &&
        data.order != Orders::Harvest2   &&
        data.order != Orders::MoveToGas  &&
        data.order != Orders::WaitForGas &&
        data.order != Orders::HarvestGas &&
        data.order != Orders::ReturnGas  &&
        data.order != Orders::ResetCollision)
      return false;

    if (data.order == Orders::ResetCollision)
      return data.carryResourceType == 1;

    //return true if BWOrder is WaitForGas, HarvestGas, or ReturnGas
    if (data.order == Orders::WaitForGas ||
        data.order == Orders::HarvestGas ||
        data.order == Orders::ReturnGas)
      return true;

    //if BWOrder is MoveToGas, Harvest1, or Harvest2 we need to do some additional checks to make sure the unit is really gathering
    Unit targ = getTarget();
    if ( targ &&
        targ->exists() && 
        targ->isCompleted() &&
        targ->getPlayer() == getPlayer() &&
        targ->getType() != UnitTypes::Resource_Vespene_Geyser &&
        (targ->getType().isRefinery() || targ->getType().isResourceDepot()) )
      return true;
    targ = getOrderTarget();
    if ( targ &&
        targ->exists() && 
        targ->isCompleted() &&
        targ->getPlayer() == getPlayer() &&
        targ->getType() != UnitTypes::Resource_Vespene_Geyser &&
        (targ->getType().isRefinery() || targ->getType().isResourceDepot()))
      return true;
    return false;
  }
  //--------------------------------------------- IS GATHERING MINERALS --------------------------------------
  bool UnitImpl::isGatheringMinerals() const
  {
    if (!data.isGathering)
      return false;

    if (data.order != Orders::Harvest1        &&
        data.order != Orders::Harvest2        &&
        data.order != Orders::MoveToMinerals  &&
        data.order != Orders::WaitForMinerals &&
        data.order != Orders::MiningMinerals  &&
        data.order != Orders::ReturnMinerals  &&
        data.order != Orders::ResetCollision)
      return false;

    if (data.order == Orders::ResetCollision)
      return data.carryResourceType == 2;

    //return true if BWOrder is WaitForMinerals, MiningMinerals, or ReturnMinerals
    if (data.order == Orders::WaitForMinerals ||
        data.order == Orders::MiningMinerals ||
        data.order == Orders::ReturnMinerals)
      return true;

    //if BWOrder is MoveToMinerals, Harvest1, or Harvest2 we need to do some additional checks to make sure the unit is really gathering
    if (getTarget() &&
        getTarget()->exists() &&
        (getTarget()->getType().isMineralField() ||
         (getTarget()->isCompleted() &&
          getTarget()->getPlayer() == getPlayer() &&
          getTarget()->getType().isResourceDepot())))
      return true;
    if (getOrderTarget() &&
        getOrderTarget()->exists() &&
        (getOrderTarget()->getType().isMineralField() ||
         (getOrderTarget()->isCompleted() &&
          getOrderTarget()->getPlayer() == getPlayer() &&
          getOrderTarget()->getType().isResourceDepot())))
      return true;
    return false;
  }
  //--------------------------------------------- IS HALLUCINATION -------------------------------------------
  bool UnitImpl::isHallucination() const
  {
    return data.isHallucination;
  }
  //--------------------------------------------- IS IDLE ----------------------------------------------------
  bool UnitImpl::isIdle() const
  {
    return data.isIdle;
  }
  //--------------------------------------------- IS INTERRUPTIBLE -------------------------------------------
  bool UnitImpl::isInterruptible() const
  {
    return data.isInterruptible;
  }
  //--------------------------------------------- IS INVINCIBLE ----------------------------------------------
  bool UnitImpl::isInvincible() const
  {
    return data.isInvincible;
  }
  //--------------------------------------------- IS LIFTED --------------------------------------------------
  bool UnitImpl::isLifted() const
  {
    return data.isLifted;
  }
  //--------------------------------------------- IS MORPHING ------------------------------------------------
  bool UnitImpl::isMorphing() const
  {
    return data.isMorphing;
  }
  //--------------------------------------------- IS MOVING --------------------------------------------------
  bool UnitImpl::isMoving() const
  {
    return data.isMoving;
  }
  //--------------------------------------------- IS PARASITED -----------------------------------------------
  bool UnitImpl::isParasited() const
  {
    return data.isParasited;
  }
  //--------------------------------------------- IS SELECTED ------------------------------------------------
  bool UnitImpl::isSelected() const
  {
    return data.isSelected;
  }
  //--------------------------------------------- IS STARTING ATTACK -----------------------------------------
  bool UnitImpl::isStartingAttack() const
  {
    return data.isStartingAttack;
  }
  //--------------------------------------------- IS STUCK ---------------------------------------------------
  bool UnitImpl::isStuck() const
  {
    return data.isStuck;
  }
  //--------------------------------------------- IS TRAINING ------------------------------------------------
  bool UnitImpl::isTraining() const
  {
    return data.isTraining;
  }
  //--------------------------------------------- IS UNDER ATTACK --------------------------------------------
  bool UnitImpl::isUnderAttack() const
  {
    return data.recentlyAttacked;
  }
  //--------------------------------------------- IS UNDER DARK SWARM ----------------------------------------
  bool UnitImpl::isUnderDarkSwarm() const
  {
    return data.isUnderDarkSwarm;
  }
  //--------------------------------------------- IS UNDER DISRUPTION WEB ------------------------------------
  bool UnitImpl::isUnderDisruptionWeb() const
  {
    return data.isUnderDWeb;
  }
  //--------------------------------------------- IS UNDER STORM ---------------------------------------------
  bool UnitImpl::isUnderStorm() const
  {
    return data.isUnderStorm;
  }
  //--------------------------------------------- IS UNPOWERED -----------------------------------------------
  bool UnitImpl::isPowered() const
  {
    return data.isPowered;
  }
  //--------------------------------------------- IS VISIBLE -------------------------------------------------
  bool UnitImpl::isVisible(Player player) const
  {
    if ( player )
      return data.isVisible[player->getID()];

    if (BroodwarImpl.self() )     // isVisible for current player
      return data.isVisible[BroodwarImpl.self()->getID()];

    for(int i = 0; i < 9; ++i)
    {
      if (data.isVisible[i])
        return true;
    }
    return false;
  }
  //--------------------------------------------- IS TARGETABLE ----------------------------------------------
  bool UnitImpl::isTargetable() const
  {
    return Templates::canTargetUnit(getGame(), const_cast<UnitImpl*>(this));
  }
  //--------------------------------------------- CAN COMMAND ------------------------------------------------
  bool UnitImpl::canCommand() const
  {
    return Templates::canCommand(getGame(), const_cast<UnitImpl*>(this));
  }
  bool UnitImpl::canCommandGrouped(bool checkCommandibility) const
  {
    return Templates::canCommandGrouped(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN TARGET UNIT --------------------------------------------
  bool UnitImpl::canTargetUnit(Unit targetUnit, bool checkCommandibility) const
  {
    return Templates::canTargetUnit(getGame(), const_cast<UnitImpl*>(this), targetUnit, checkCommandibility);
  }
  //--------------------------------------------- CAN ATTACK -------------------------------------------------
  bool UnitImpl::canAttack(bool checkCommandibility) const
  {
    return Templates::canAttack(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canAttack(Position target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canAttack(getGame(), const_cast<UnitImpl*>(this), target, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
  }
  bool UnitImpl::canAttack(Unit target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canAttack(getGame(), const_cast<UnitImpl*>(this), target, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
  }
  bool UnitImpl::canAttackGrouped(bool checkCommandibilityGrouped, bool checkCommandibility) const
  {
    return Templates::canAttackGrouped(getGame(), const_cast<UnitImpl*>(this), checkCommandibilityGrouped, checkCommandibility);
  }
  bool UnitImpl::canAttackGrouped(Position target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility) const
  {
    return Templates::canAttackGrouped(getGame(), const_cast<UnitImpl*>(this), target, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibilityGrouped, checkCommandibility);
  }
  bool UnitImpl::canAttackGrouped(Unit target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility) const
  {
    return Templates::canAttackGrouped(getGame(), const_cast<UnitImpl*>(this), target, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibilityGrouped, checkCommandibility);
  }
  //--------------------------------------------- CAN ATTACK MOVE --------------------------------------------
  bool UnitImpl::canAttackMove(bool checkCommandibility) const
  {
    return Templates::canAttackMove(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canAttackMoveGrouped(bool checkCommandibilityGrouped, bool checkCommandibility) const
  {
    return Templates::canAttackMoveGrouped(getGame(), const_cast<UnitImpl*>(this), checkCommandibilityGrouped, checkCommandibility);
  }
  //--------------------------------------------- CAN ATTACK UNIT --------------------------------------------
  bool UnitImpl::canAttackUnit(bool checkCommandibility) const
  {
    return Templates::canAttackUnit(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canAttackUnit(Unit targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canAttackUnit(getGame(), const_cast<UnitImpl*>(this), targetUnit, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
  }
  bool UnitImpl::canAttackUnitGrouped(bool checkCommandibilityGrouped, bool checkCommandibility) const
  {
    return Templates::canAttackUnitGrouped(getGame(), const_cast<UnitImpl*>(this), checkCommandibilityGrouped, checkCommandibility);
  }
  bool UnitImpl::canAttackUnitGrouped(Unit targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility) const
  {
    return Templates::canAttackUnitGrouped(getGame(), const_cast<UnitImpl*>(this), targetUnit, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibilityGrouped, checkCommandibility);
  }
  //--------------------------------------------- CAN BUILD --------------------------------------------------
  bool UnitImpl::canBuild(bool checkCommandibility) const
  {
    return Templates::canBuild(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canBuild(UnitType uType, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canBuild(getGame(), const_cast<UnitImpl*>(this), uType, checkCanIssueCommandType, checkCommandibility);
  }
  bool UnitImpl::canBuild(UnitType uType, BWAPI::TilePosition tilePos, bool checkTargetUnitType, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canBuild(getGame(), const_cast<UnitImpl*>(this), uType, tilePos, checkTargetUnitType, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN BUILD ADDON --------------------------------------------
  bool UnitImpl::canBuildAddon(bool checkCommandibility) const
  {
    return Templates::canBuildAddon(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canBuildAddon(UnitType uType, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canBuildAddon(getGame(), const_cast<UnitImpl*>(this), uType, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN TRAIN --------------------------------------------------
  bool UnitImpl::canTrain(bool checkCommandibility) const
  {
    return Templates::canTrain(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canTrain(UnitType uType, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canTrain(getGame(), const_cast<UnitImpl*>(this), uType, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN MORPH --------------------------------------------------
  bool UnitImpl::canMorph(bool checkCommandibility) const
  {
    return Templates::canMorph(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canMorph(UnitType uType, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canMorph(getGame(), const_cast<UnitImpl*>(this), uType, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN RESEARCH -----------------------------------------------
  bool UnitImpl::canResearch(bool checkCommandibility) const
  {
    return Templates::canResearch(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canResearch(TechType type, bool checkCanIssueCommandType) const
  {
    return Templates::canResearch(getGame(), const_cast<UnitImpl*>(this), type, checkCanIssueCommandType);
  }
  //--------------------------------------------- CAN UPGRADE ------------------------------------------------
  bool UnitImpl::canUpgrade(bool checkCommandibility) const
  {
    return Templates::canUpgrade(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canUpgrade(UpgradeType type, bool checkCanIssueCommandType) const
  {
    return Templates::canUpgrade(getGame(), const_cast<UnitImpl*>(this), type, checkCanIssueCommandType);
  }
  //--------------------------------------------- CAN SET RALLY POINT ----------------------------------------
  bool UnitImpl::canSetRallyPoint(bool checkCommandibility) const
  {
    return Templates::canSetRallyPoint(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canSetRallyPoint(Position target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canSetRallyPoint(getGame(), const_cast<UnitImpl*>(this), target, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
  }
  bool UnitImpl::canSetRallyPoint(Unit target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canSetRallyPoint(getGame(), const_cast<UnitImpl*>(this), target, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN SET RALLY POSITION -------------------------------------
  bool UnitImpl::canSetRallyPosition(bool checkCommandibility) const
  {
    return Templates::canSetRallyPosition(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN SET RALLY UNIT -----------------------------------------
  bool UnitImpl::canSetRallyUnit(bool checkCommandibility) const
  {
    return Templates::canSetRallyUnit(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canSetRallyUnit(Unit targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canSetRallyUnit(getGame(), const_cast<UnitImpl*>(this), targetUnit, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN MOVE ---------------------------------------------------
  bool UnitImpl::canMove(bool checkCommandibility) const
  {
    return Templates::canMove(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canMoveGrouped(bool checkCommandibilityGrouped, bool checkCommandibility) const
  {
    return Templates::canMoveGrouped(getGame(), const_cast<UnitImpl*>(this), checkCommandibilityGrouped, checkCommandibility);
  }
  //--------------------------------------------- CAN PATROL -------------------------------------------------
  bool UnitImpl::canPatrol(bool checkCommandibility) const
  {
    return Templates::canPatrol(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canPatrolGrouped(bool checkCommandibilityGrouped, bool checkCommandibility) const
  {
    return Templates::canPatrolGrouped(getGame(), const_cast<UnitImpl*>(this), checkCommandibilityGrouped, checkCommandibility);
  }
  //--------------------------------------------- CAN FOLLOW -------------------------------------------------
  bool UnitImpl::canFollow(bool checkCommandibility) const
  {
    return Templates::canFollow(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canFollow(Unit targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canFollow(getGame(), const_cast<UnitImpl*>(this), targetUnit, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN GATHER -------------------------------------------------
  bool UnitImpl::canGather(bool checkCommandibility) const
  {
    return Templates::canGather(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canGather(Unit targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canGather(getGame(), const_cast<UnitImpl*>(this), targetUnit, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN RETURN CARGO -------------------------------------------
  bool UnitImpl::canReturnCargo(bool checkCommandibility) const
  {
    return Templates::canReturnCargo(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN HOLD POSITION ------------------------------------------
  bool UnitImpl::canHoldPosition(bool checkCommandibility) const
  {
    return Templates::canHoldPosition(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN STOP ---------------------------------------------------
  bool UnitImpl::canStop(bool checkCommandibility) const
  {
    return Templates::canStop(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN REPAIR -------------------------------------------------
  bool UnitImpl::canRepair(bool checkCommandibility) const
  {
    return Templates::canRepair(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canRepair(Unit targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canRepair(getGame(), const_cast<UnitImpl*>(this), targetUnit, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN BURROW -------------------------------------------------
  bool UnitImpl::canBurrow(bool checkCommandibility) const
  {
    return Templates::canBurrow(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN UNBURROW -----------------------------------------------
  bool UnitImpl::canUnburrow(bool checkCommandibility) const
  {
    return Templates::canUnburrow(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN CLOAK --------------------------------------------------
  bool UnitImpl::canCloak(bool checkCommandibility) const
  {
    return Templates::canCloak(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN DECLOAK ------------------------------------------------
  bool UnitImpl::canDecloak(bool checkCommandibility) const
  {
    return Templates::canDecloak(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN SIEGE --------------------------------------------------
  bool UnitImpl::canSiege(bool checkCommandibility) const
  {
    return Templates::canSiege(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN UNSIEGE ------------------------------------------------
  bool UnitImpl::canUnsiege(bool checkCommandibility) const
  {
    return Templates::canUnsiege(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN LIFT ---------------------------------------------------
  bool UnitImpl::canLift(bool checkCommandibility) const
  {
    return Templates::canLift(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN LAND ---------------------------------------------------
  bool UnitImpl::canLand(bool checkCommandibility) const
  {
    return Templates::canLand(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canLand(TilePosition target, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canLand(getGame(), const_cast<UnitImpl*>(this), target, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN LOAD ---------------------------------------------------
  bool UnitImpl::canLoad(bool checkCommandibility) const
  {
    return Templates::canLoad(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canLoad(Unit targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canLoad(getGame(), const_cast<UnitImpl*>(this), targetUnit, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN UNLOAD -------------------------------------------------
  bool UnitImpl::canUnloadWithOrWithoutTarget(bool checkCommandibility) const
  {
    return Templates::canUnloadWithOrWithoutTarget(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canUnloadAtPosition(Position targDropPos, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canUnloadAtPosition(getGame(), const_cast<UnitImpl*>(this), targDropPos, checkCanIssueCommandType, checkCommandibility);
  }
  bool UnitImpl::canUnload(bool checkCommandibility) const
  {
    return Templates::canUnload(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canUnload(Unit targetUnit, bool checkCanTargetUnit, bool checkPosition, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canUnload(getGame(), const_cast<UnitImpl*>(this), targetUnit, checkCanTargetUnit, checkPosition, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN UNLOAD ALL ---------------------------------------------
  bool UnitImpl::canUnloadAll(bool checkCommandibility) const
  {
    return Templates::canUnloadAll(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN UNLOAD ALL POSITION ------------------------------------
  bool UnitImpl::canUnloadAllPosition(bool checkCommandibility) const
  {
    return Templates::canUnloadAllPosition(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canUnloadAllPosition(Position targDropPos, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canUnloadAllPosition(getGame(), const_cast<UnitImpl*>(this), targDropPos, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN RIGHT CLICK --------------------------------------------
  bool UnitImpl::canRightClick(bool checkCommandibility) const
  {
    return Templates::canRightClick(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canRightClick(Position target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canRightClick(getGame(), const_cast<UnitImpl*>(this), target, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
  }
  bool UnitImpl::canRightClick(Unit target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canRightClick(getGame(), const_cast<UnitImpl*>(this), target, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
  }
  bool UnitImpl::canRightClickGrouped(bool checkCommandibilityGrouped, bool checkCommandibility) const
  {
    return Templates::canRightClickGrouped(getGame(), const_cast<UnitImpl*>(this), checkCommandibilityGrouped, checkCommandibility);
  }
  bool UnitImpl::canRightClickGrouped(Position target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility) const
  {
    return Templates::canRightClickGrouped(getGame(), const_cast<UnitImpl*>(this), target, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibilityGrouped, checkCommandibility);
  }
  bool UnitImpl::canRightClickGrouped(Unit target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility) const
  {
    return Templates::canRightClickGrouped(getGame(), const_cast<UnitImpl*>(this), target, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibilityGrouped, checkCommandibility);
  }
  //--------------------------------------------- CAN RIGHT CLICK POSITION -----------------------------------
  bool UnitImpl::canRightClickPosition(bool checkCommandibility) const
  {
    return Templates::canRightClickPosition(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canRightClickPositionGrouped(bool checkCommandibilityGrouped, bool checkCommandibility) const
  {
    return Templates::canRightClickPositionGrouped(getGame(), const_cast<UnitImpl*>(this), checkCommandibilityGrouped, checkCommandibility);
  }
  //--------------------------------------------- CAN RIGHT CLICK UNIT ---------------------------------------
  bool UnitImpl::canRightClickUnit(bool checkCommandibility) const
  {
    return Templates::canRightClickUnit(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canRightClickUnit(Unit targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canRightClickUnit(getGame(), const_cast<UnitImpl*>(this), targetUnit, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
  }
  bool UnitImpl::canRightClickUnitGrouped(bool checkCommandibilityGrouped, bool checkCommandibility) const
  {
    return Templates::canRightClickUnitGrouped(getGame(), const_cast<UnitImpl*>(this), checkCommandibilityGrouped, checkCommandibility);
  }
  bool UnitImpl::canRightClickUnitGrouped(Unit targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility) const
  {
    return Templates::canRightClickUnitGrouped(getGame(), const_cast<UnitImpl*>(this), targetUnit, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibilityGrouped, checkCommandibility);
  }
  //--------------------------------------------- CAN HALT CONSTRUCTION --------------------------------------
  bool UnitImpl::canHaltConstruction(bool checkCommandibility) const
  {
    return Templates::canHaltConstruction(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN CANCEL CONSTRUCTION ------------------------------------
  bool UnitImpl::canCancelConstruction(bool checkCommandibility) const
  {
    return Templates::canCancelConstruction(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN CANCEL ADDON -------------------------------------------
  bool UnitImpl::canCancelAddon(bool checkCommandibility) const
  {
    return Templates::canCancelAddon(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN CANCEL TRAIN -------------------------------------------
  bool UnitImpl::canCancelTrain(bool checkCommandibility) const
  {
    return Templates::canCancelTrain(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN CANCEL TRAIN SLOT --------------------------------------
  bool UnitImpl::canCancelTrainSlot(bool checkCommandibility) const
  {
    return Templates::canCancelTrainSlot(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canCancelTrainSlot(int slot, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canCancelTrainSlot(getGame(), const_cast<UnitImpl*>(this), slot, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN CANCEL MORPH -------------------------------------------
  bool UnitImpl::canCancelMorph(bool checkCommandibility) const
  {
    return Templates::canCancelMorph(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN CANCEL RESEARCH ----------------------------------------
  bool UnitImpl::canCancelResearch(bool checkCommandibility) const
  {
    return Templates::canCancelResearch(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN CANCEL UPGRADE -----------------------------------------
  bool UnitImpl::canCancelUpgrade(bool checkCommandibility) const
  {
    return Templates::canCancelUpgrade(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  //--------------------------------------------- CAN USE TECH -----------------------------------------------
  bool UnitImpl::canUseTechWithOrWithoutTarget(bool checkCommandibility) const
  {
    return Templates::canUseTechWithOrWithoutTarget(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canUseTechWithOrWithoutTarget(BWAPI::TechType tech, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canUseTechWithOrWithoutTarget(getGame(), const_cast<UnitImpl*>(this), tech, checkCanIssueCommandType, checkCommandibility);
  }
  bool UnitImpl::canUseTech(BWAPI::TechType tech, Unit target, bool checkCanTargetUnit, bool checkTargetsType, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canUseTech(getGame(), const_cast<UnitImpl*>(this), tech, target, checkCanTargetUnit, checkTargetsType, checkCanIssueCommandType, checkCommandibility);
  }
  bool UnitImpl::canUseTech(BWAPI::TechType tech, Position target, bool checkCanTargetUnit, bool checkTargetsType, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canUseTech(getGame(), const_cast<UnitImpl*>(this), tech, target, checkCanTargetUnit, checkTargetsType, checkCanIssueCommandType, checkCommandibility);
  }
  bool UnitImpl::canUseTechWithoutTarget(BWAPI::TechType tech, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canUseTechWithoutTarget(getGame(), const_cast<UnitImpl*>(this), tech, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN USE TECH UNIT ------------------------------------------
  bool UnitImpl::canUseTechUnit(BWAPI::TechType tech, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canUseTechUnit(getGame(), const_cast<UnitImpl*>(this), tech, checkCanIssueCommandType, checkCommandibility);
  }
  bool UnitImpl::canUseTechUnit(BWAPI::TechType tech, Unit targetUnit, bool checkCanTargetUnit, bool checkTargetsUnits, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canUseTechUnit(getGame(), const_cast<UnitImpl*>(this), tech, targetUnit, checkCanTargetUnit, checkTargetsUnits, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN USE TECH POSITION --------------------------------------
  bool UnitImpl::canUseTechPosition(BWAPI::TechType tech, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canUseTechPosition(getGame(), const_cast<UnitImpl*>(this), tech, checkCanIssueCommandType, checkCommandibility);
  }
  bool UnitImpl::canUseTechPosition(BWAPI::TechType tech, Position target, bool checkTargetsPositions, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canUseTechPosition(getGame(), const_cast<UnitImpl*>(this), tech, target, checkTargetsPositions, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN PLACE COP ----------------------------------------------
  bool UnitImpl::canPlaceCOP(bool checkCommandibility) const
  {
    return Templates::canPlaceCOP(getGame(), const_cast<UnitImpl*>(this), checkCommandibility);
  }
  bool UnitImpl::canPlaceCOP(TilePosition target, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canPlaceCOP(getGame(), const_cast<UnitImpl*>(this), target, checkCanIssueCommandType, checkCommandibility);
  }
  //--------------------------------------------- CAN ISSUE COMMAND TYPE -------------------------------------
  bool UnitImpl::canIssueCommandType(BWAPI::UnitCommandType ct, bool checkCommandibility) const
  {
    return Templates::canIssueCommandType(getGame(), const_cast<UnitImpl*>(this), ct, checkCommandibility);
  }
  bool UnitImpl::canIssueCommandTypeGrouped(BWAPI::UnitCommandType ct, bool checkCommandibilityGrouped, bool checkCommandibility) const
  {
    return Templates::canIssueCommandTypeGrouped(getGame(), const_cast<UnitImpl*>(this), ct, checkCommandibilityGrouped, checkCommandibility);
  }
  //--------------------------------------------- CAN ISSUE COMMAND ------------------------------------------
  bool UnitImpl::canIssueCommand(UnitCommand command, bool checkCanUseTechPositionOnPositions, bool checkCanUseTechUnitOnUnits, bool checkCanBuildUnitType, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) const
  {
    return Templates::canIssueCommand(getGame(), const_cast<UnitImpl*>(this), command, checkCanUseTechPositionOnPositions, checkCanUseTechUnitOnUnits, checkCanBuildUnitType, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
  }
  bool UnitImpl::canIssueCommandGrouped(UnitCommand command, bool checkCanUseTechPositionOnPositions, bool checkCanUseTechUnitOnUnits, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility) const
  {
    return Templates::canIssueCommandGrouped(getGame(), const_cast<UnitImpl*>(this), command, checkCanUseTechPositionOnPositions, checkCanUseTechUnitOnUnits, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibilityGrouped, checkCommandibility);
  }
}
