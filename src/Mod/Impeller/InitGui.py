# Impeller gui init module
# (c) 2001 Juergen Riegel LGPL

class ImpellerWorkbench ( Workbench ):
	"Impeller workbench object"
	MenuText = "Impeller"
	ToolTip = "Impeller workbench"
	def Initialize(self):
		# load the module
		import ImpellerGui
	def GetClassName(self):
		return "ImpellerGui::Workbench"

Gui.addWorkbench(ImpellerWorkbench())
