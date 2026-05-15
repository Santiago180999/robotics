#include "Problem/ProblemGenerator.hpp"
namespace Grid
{

void ProblemGenerator::generateWorld(size_t size, Grid::MovementType moveType)
{
    std::unique_ptr<World> wrl = m_generator.GenerateWorld(size, moveType);
    m_problem->setWorld(std::move(wrl));
}

std::unique_ptr<Grid::Problem> ProblemGenerator::getProblem()
{
    return std::move(m_problem);
}

std::unique_ptr<Grid::Problem> ProblemGenerator::generateRandomProblem(ProblemParameters& worldParams)
{
    generateWorld(worldParams.size, worldParams.moveType);
    m_problem->setStartState(m_generator.GenerateRandomPoint(m_problem->getWorld()));
    m_problem->setGoalState(m_generator.GenerateRandomPoint(m_problem->getWorld()));

    return std::move(m_problem);
}

std::unique_ptr<Grid::Problem> ProblemGenerator::generateSpecificProblem(ProblemParameters& worldParams)
{
    m_generator.setSeed(worldParams.seed);
    generateWorld(worldParams.size, worldParams.moveType);
    m_problem->setStartState(m_generator.GenerateRandomPoint(m_problem->getWorld()));
    m_problem->setGoalState(m_generator.GenerateRandomPoint(m_problem->getWorld()));
    //m_problem->setStartState(worldParams.startState);
    //m_problem->setGoalState(worldParams.goalState);

    return std::move(m_problem);

}

uint ProblemGenerator::getSeed()
{
    return m_generator.getSeed();
}




}