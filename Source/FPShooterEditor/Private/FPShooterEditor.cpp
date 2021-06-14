#include "FPShooterEditor.h"
#include "LevelEditor.h"
#include "IAssetTools.h"
#include "MyCustomAssetActions.h"

IMPLEMENT_GAME_MODULE(FFPShooterEditorModule, FPShooterEditor);

void FFPShooterEditorModule::StartupModule()
{
	FPShooterCommands::Register();
	TSharedPtr<FUICommandList> CommandList = MakeShareable(new FUICommandList());
	CommandList->MapAction(FPShooterCommands::Get().MyButton, FExecuteAction::CreateRaw(this, &FFPShooterEditorModule::MyButton_Clicked), FCanExecuteAction()); // 버튼 클릭 시 실행할 함수 바인딩
	ToolbarExtender = MakeShareable(new FExtender());
	Extension = ToolbarExtender->AddMenuExtension("LevelEditor", EExtensionHook::Before, CommandList, FMenuExtensionDelegate::CreateRaw(this, &FFPShooterEditorModule::AddMenuExtension)); // AddMenuExtension을 호출하여 창의 하위메뉴 중 레벨에디터 위(Before)에 새 엔트리 Cookbook을 생성한다.
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(ToolbarExtender);
	// Extension = ToolbarExtender->AddToolBarExtension("Compile", EExtensionHook::Before, CommandList, FToolBarExtensionDelegate::CreateRaw(this, &FFPShooterEditorModule::AddToolbarExtension)); // 에디터 툴바에 새 버튼 생성 (Compile 확장점(버튼영역) 이전(Before)에 생성) // LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);

	// 애셋에 추가할 사용자 정의 액션을 처리하도록 엔진(에디터)에 알려줘야 한다. 이를 위해서는 Asset Tool 모듈에 액션 클래스를 등록해야 한다.
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get(); // Asset Tools 모듈은 애셋에 액션을 추가하도록 지원하는 모듈이다.
	auto Actions = MakeShareable(new MyCustomAssetActions()); // 사용자정의 액션 인스턴싱
	AssetTools.RegisterAssetTypeActions(Actions); // 애셋 툴(에디터)에 사용자정의 액션을 추가한다. 
	CreatedAssetTypeActions.Add(Actions); // 나중에 인스턴스를 해제할 수 있도록 액션 인스턴스(Actions)에 대한 참조를 CreatedAssetTypeActions 배열에 저장한다.
}

void FFPShooterEditorModule::ShutdownModule()
{
	ToolbarExtender->RemoveExtension(Extension.ToSharedRef()); // 이 모듈이 해제 시 추가한 버튼도 제거
	Extension.Reset();
	ToolbarExtender.Reset();

	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get(); // 애셋 툴 모듈을 로드하고
	for (auto Action : CreatedAssetTypeActions) // 애셋 툴에 등록된 액션이 남아있을 경우
	{
		AssetTools.UnregisterAssetTypeActions(Action.ToSharedRef()); // CreatedAssetTypeActions에 저장된 참조를 활용하여 애셋 툴에 등록된 액션을 제거한다.
	}
}
