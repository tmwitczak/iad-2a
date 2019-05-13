#ifndef IAD_2A_PERCEPTRON_LAYER_HPP
#define IAD_2A_PERCEPTRON_LAYER_HPP
///////////////////////////////////////////////////////////////////// | Includes
#include "activation-function.hpp"
#include "sigmoid.hpp"
#include "rectified-linear-unit.hpp"
#include "training-example.hpp"

#include <Eigen>
#include <vector>
#include <memory>
#include <cereal/access.hpp>

//////////////////////////////////////////////////// | Namespace: NeuralNetworks
namespace NeuralNetworks
{
    ///////////////////////////////////////////////// | Class: PerceptronLayer <
    class PerceptronLayer
    final
    {
    public:
        //========================================================= | Methods <<
        //------------------------------------------------- | Static methods <<<
        static void initialiseRandomSeed
                (int const &seed);

        //--------------------------------------------------- | Constructors <<<
        PerceptronLayer
                (int const &numberOfInputs,
                 int const &numberOfOutputs,
                 ActivationFunction const &activationFunction = Sigmoid {},
                 bool const &enableBias = true);

        PerceptronLayer
                (std::string const &filename);

        //------------------------------------------------------ | Operators <<<
        Eigen::VectorXd operator()
                (Eigen::VectorXd const &inputs) const;

        //------------------------------------------------- | Main behaviour <<<
        Eigen::VectorXd feedForward
                (Eigen::VectorXd const &inputs) const;

        Eigen::VectorXd backpropagate
                (Eigen::VectorXd const &inputs,
                 Eigen::VectorXd const &errors) const;

        void calculateNextStep
                (Eigen::VectorXd const &inputs,
                 Eigen::VectorXd const &errors,
                 Eigen::VectorXd const &outputs);

        void update
                (double const &learningCoefficient,
                 double const &momentumCoefficient);

        void saveToFile
                (std::string const &filename) const;

        //--------------------------------------------------------- | Traits <<<
        int numberOfInputs
                () const;

        int numberOfOutputs
                () const;

    private:
        //============================================================ | Data <<
        Eigen::MatrixXd weights, deltaWeights, momentumWeights;
        Eigen::VectorXd biases, deltaBiases, momentumBiases;
        std::unique_ptr<ActivationFunction> activationFunction;
        int currentNumberOfSteps;
        bool isBiasEnabled;

        //======================================================= | Behaviour <<
        //-------------------------------------------------- | Serialization <<<
        friend class cereal::access;

        template <typename Archive>
        void save
                (Archive &archive) const;

        template <typename Archive>
        void load
                (Archive &archive);

        //----------------------------------------------- | Helper functions <<<
        void applyAverageOfDeltaStepsToMomentumStep
                (double const learningCoefficient,
                 double const momentumCoefficient);

        void applyMomentumStepToWeightsAndBiases
                ();

        void resetStepData
                ();
    };
}

////////////////////////////////////////////////////////////////////////////////
#endif // IAD_2A_PERCEPTRON_LAYER_HPP