/*---------------------------------------------------------------------------*\

    DAFoam  : Discrete Adjoint with OpenFOAM
    Version : v2

    Description:
        Child class for DASimpleTFoam

\*---------------------------------------------------------------------------*/

#ifndef DAResidualSimpleTFoamTest_H
#define DAResidualSimpleTFoamTest_H

#include "DAResidual.H"
#include "addToRunTimeSelectionTable.H"
#include "simpleControl.H"
#include "adjustPhi.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
      Class DAResidualSimpleTFoam Declaration
\*---------------------------------------------------------------------------*/

class DAResidualSimpleTFoamTest
    : public DAResidual
{
protected:
    /// \name These are state variables, state residuals, and partial derivatives
    //@{
    volVectorField& U_;
    volVectorField URes_;
    volVectorField UResPartDeriv_;

    volScalarField& p_;
    volScalarField pRes_;
    volScalarField pResPartDeriv_;

    volScalarField& T_;
    volScalarField TRes_;
    volScalarField TResPartDeriv_;

    surfaceScalarField& phi_;
    surfaceScalarField phiRes_;
    surfaceScalarField phiResPartDeriv_;
    //@}

    /// alpha porosity term
    volScalarField& alphaPorosity_;

    volScalarField& alphat_;

    dimensionedScalar Q;

    scalar Pr_ = -9999.0;

    scalar Prt_ = -9999.0;

    /// DATurbulenceModel object
    DATurbulenceModel& daTurb_;

    /// simpleControl object which will be initialized in this class
    simpleControl simple_;

public:
    TypeName("DASimpleTFoamTest");
    // Constructors

    //- Construct from components
    DAResidualSimpleTFoamTest(
        const word modelType,
        const fvMesh& mesh,
        const DAOption& daOption,
        const DAModel& daModel,
        const DAIndex& daIndex);

    //- Destructor
    virtual ~DAResidualSimpleTFoamTest()
    {
    }

    // Members

    /// clear the members
    virtual void clear();

    /// compute residual
    virtual void calcResiduals(const dictionary& options);

    /// update any intermediate variables that are dependent on state variables and are used in calcResiduals
    virtual void updateIntermediateVariables();

    /// update the boundary condition for all the states in the selected solver
    virtual void correctBoundaryConditions();
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
