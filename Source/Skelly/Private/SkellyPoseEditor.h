//-------------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2014 Vadim Macagon
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//-------------------------------------------------------------------------------
#pragma once

#include "Toolkits/AssetEditorToolkit.h"

class USkellyPose;

namespace Skelly {

/** Editor for USkellyPose assets. */
class FPoseEditor : public FAssetEditorToolkit, public FGCObject
{
public: // FAssetEditorToolkit interface
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& tabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& tabManager) override;

	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;

public: // FGCObject interface
	virtual void AddReferencedObjects(FReferenceCollector& collector) override;

public:
	FPoseEditor();

	void InitPoseEditor(
		EToolkitMode::Type toolkitMode, TSharedPtr<IToolkitHost>& editWithinLevelEditor,
		USkellyPose* poseToEdit
	);

private:
	TSharedRef<SDockTab> OnSpawnSkeletonTab(const FSpawnTabArgs& args);
	TSharedRef<SDockTab> OnSpawnViewportTab(const FSpawnTabArgs& args);
	TSharedRef<SDockTab> OnSpawnDetailsTab(const FSpawnTabArgs& args);

private:
	/** The pose currently being edited. */
	USkellyPose* _currentPose;

	FText _skeletonTabTitle;
	FText _viewportTabTitle;
	FText _detailsTabTitle;

private:
	static FName PoseEditorAppName;
};

} // namespace Skelly