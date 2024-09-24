// ----------------------------------------------------------------------------
// Generated by ScriptObjectFactory [Sat Sep 27 01:24:57 2003]
// 
// File        : 
// Class       : FeedWatcherScriptObject
// class layer : Automatic Object Scripting
// ----------------------------------------------------------------------------
#include "precomp.h"

#include "feedwatch.h"
#include "FeedWatcherSO.h"
// ScriptController Instance
static FeedWatcherScriptController _feedWatcherScriptController;FeedWatcherScriptController *feedWatcherScriptController = &_feedWatcherScriptController;

// Function Descriptor Table
function_descriptor_struct FeedWatcherScriptController::exportedFunctions[] =  {
  { L"setFeed", 1, script_setFeed },
  { L"releaseFeed", 0, script_releaseFeed },
  { L"onFeedChange", 1, script_feedwatcher_onFeedChange },
};

// Script Object Methods
FeedWatcherScriptObject::FeedWatcherScriptObject()  {
  if (!getScriptObject()) return;
  feedWatcherScriptObject_init();
}

FeedWatcherScriptObject::~FeedWatcherScriptObject() {
}

void FeedWatcherScriptObject::feedWatcherScriptObject_init()  {
  // Assign the script interface to this instance.
  getScriptObject()->vcpu_setInterface(FeedWatcherGuid, (void *)static_cast<FeedWatcher*>(this));
  // Assign the class name to this instance.
  getScriptObject()->vcpu_setClassName(L"FeedWatcher");
  // Assign the controller instance to this script object instance.
  getScriptObject()->vcpu_setController(feedWatcherScriptController);
}

// Script Object Methods

void FeedWatcherScriptObject::feedwatcher_onFeedChange(const wchar_t *data) {
  FeedWatcherScriptController::script_feedwatcher_onFeedChange(SCRIPT_CALL, getScriptObject(), MAKE_SCRIPT_STRING(data));
}

scriptVar /*int */ FeedWatcherScriptController::script_setFeed(SCRIPT_FUNCTION_PARAMS, ScriptObject *_pSO, scriptVar /*const char **/ feedid) {
  // Begin all script methods with the init block.
  SCRIPT_FUNCTION_INIT;
  // Find the proper pointer for the "this" object, _pSO.
  FeedWatcher*_pObj = static_cast<FeedWatcher*>(_pSO->vcpu_getInterface(FeedWatcherGuid));
  if (_pObj) {
    return MAKE_SCRIPT_INT(_pObj->setFeed(GET_SCRIPT_STRING(feedid)));
  }
  RETURN_SCRIPT_ZERO;
}

scriptVar /*void */ FeedWatcherScriptController::script_releaseFeed(SCRIPT_FUNCTION_PARAMS, ScriptObject *_pSO) {
  // Begin all script methods with the init block.
  SCRIPT_FUNCTION_INIT;
  // Find the proper pointer for the "this" object, _pSO.
  FeedWatcher*_pObj = static_cast<FeedWatcher*>(_pSO->vcpu_getInterface(FeedWatcherGuid));
  if (_pObj) {
    // Then properly call the hosted object;
    _pObj->releaseFeed();
  }
  RETURN_SCRIPT_VOID;
}

scriptVar /*void */ FeedWatcherScriptController::script_feedwatcher_onFeedChange(SCRIPT_FUNCTION_PARAMS, ScriptObject *_pSO, scriptVar /*const char **/ data) {
  // Begin all script methods with the init block
  SCRIPT_FUNCTION_INIT;
  // Honnor C++ hooks
  PROCESS_HOOKS1(_pSO, feedWatcherScriptController, data);
  // If there are no script hooks to execute, we abort here.
  SCRIPT_FUNCTION_CHECKABORTEVENT;
  // Otherwise we execute the script methods by calling this.
  SCRIPT_EXEC_EVENT1(_pSO, data);
}

// Script Controller 

// This method returns the human readable name of the class in script files.
const wchar_t *FeedWatcherScriptController::getClassName() {
  return L"FeedWatcher";
}

// This method returns the human readable name of the parent of this class.
const wchar_t *FeedWatcherScriptController::getAncestorClassName() {
  return FEEDWATCHER_SCRIPTPARENTCLASS;
}

// This method returns the controller object for the parent class.
ScriptObjectController *FeedWatcherScriptController::getAncestorController() {
  /* XML-Template-TODO : Support inheritance */
  return NULL;
}

// This method returns the number of methods this class publishes.
int FeedWatcherScriptController::getNumFunctions() {
  return sizeof(exportedFunctions) / sizeof(function_descriptor_struct);
}

// This method returns the block of published function descriptors.
const function_descriptor_struct *FeedWatcherScriptController::getExportedFunctions() {
  return exportedFunctions;
}

// This method returns the GUID assigned to this script class.
GUID FeedWatcherScriptController::getClassGuid() {
  return FeedWatcherGuid;
}

// This method creates and returns a new script class instance.
ScriptObject *FeedWatcherScriptController::instantiate() {
  FeedWatcher*_pObj = new FeedWatcher();
  ASSERT(_pObj != NULL);
  return _pObj->getScriptObject();
}

// This method deletes a given script class instance.
void FeedWatcherScriptController::destroy(ScriptObject *o) {
  FeedWatcher*_pObj = static_cast<FeedWatcher*>(o->vcpu_getInterface(FeedWatcherGuid));
  ASSERT(_pObj != NULL);
  delete _pObj;
}

// This method returns an encapsulated interface for the given instance.
void *FeedWatcherScriptController::encapsulate(ScriptObject *o) {
  // No automatic encapsulation
  return NULL;
}

// This method frees a previously encapsulated interface.
void FeedWatcherScriptController::deencapsulate(void *o) {
}
