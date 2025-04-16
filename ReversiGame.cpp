#include "ReversiGame.h"

namespace Reversi
{
	ReversiGame::ReversiGame(IReversiContext* ctx, IReversiInput* inp, IReversiView* vw) : context(ctx), input(inp), view(vw)
	{

	}

	void ReversiGame::Execute()
	{
		view->Initialize();
		StartGame();
	}

	void ReversiGame::StartGame()
	{	
		// initialize the context

		input->SetInputLock(true);
		view->ShowGameStarting(context, [=]() {
			input->SetInputLock(false);
			WaitForPlayerInput();
		});
	}

	void ReversiGame::WaitForPlayerInput()
	{
		input->SetInputLock(false);
		// view->ShowPlaceablePreview

		input->WaitPreviewInput([=](BoardPosition position) {
			view->ClearCapturablePreview();
			// view->ShowCapturablePreview
		});

		input->WaitPlacingInput([=](BoardPosition position) {
			if (ProcessDiskPlacement(position)) {
				input->SetInputLock(true);
				view->ClearPlaceablePreview();
				view->ClearCapturablePreview();
			}
		});
	}

	bool ReversiGame::ProcessDiskPlacement(BoardPosition placingPosition)
	{
		// If the placement is not valid, return false.
		// Update the board(slot status) to what it will look like after placing this piece on the placingPosition.
		
		// view->ShowDiskPlacing(playerColor, placingPosition, [=]() {
		// 	view->ShowDiskFlipping(capturableDisks, [=]() {
		// 		ProcessStateChange();
		// 	});
		// });
		return true;
	}

	void ReversiGame::ProcessStateChange()
	{
		// auto prevState = context->GetCurrentState();
		// auto nextState = context->SetCurrentState(the next state);
		
		// view->ShowStateChanging(nextState, prevState, [=]() {
		// 		After the state change show ends...
		// });
	}

	void ReversiGame::RestartGame()
	{
		// Clear the data of prev game.
		StartGame();
	}
}
