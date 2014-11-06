    #***
  #*********************************************************************
#*************************************************************************
#*** 
#*** GizmoDaemon Config Script
#*** 	Powermate REVGUI config
#***
#*****************************************
  #*****************************************
    #***

"""

  Copyright (c) 2007, Gizmo Daemon Team
  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at 

	http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and 
  limitations under the License. 
  
"""

############################
# Imports
##########################

from GizmoDaemon import *
from GizmoScriptRunningApplication import *
import time

ENABLED = True
VERSION_NEEDED = 3.2
INTERESTED_CLASSES = [GizmoEventClass.Powermate]
INTERESTED_APPLICATION = "REV_HMI_GETZ"

############################
# PowermateDefault Class definition
##########################

class PowermateRevGui(GizmoScriptRunningApplication):
	"""
	REV GUI Powermate Event Mapping
	"""
	
	############################
	# Public Functions
	##########################
			
	def onDeviceEvent(self, Event, Gizmo = None):
		"""
		Called from Base Class' onEvent method.
		See GizmodDispatcher.onEvent documention for an explanation of this function
		"""
		#Ensure Powermate is connected
		if len(Gizmod.Powermates) < 1:
			print "No Powermate connected"
			return False
		
	   	# Primary function
		if self.Primary and Event.Type == GizmoEventType.EV_REL:
			if not Gizmo.getKeyState(GizmoKey.BTN_0):
				if Event.Value < 0:				
					Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_Q)
					Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_BACKSPACE)
					#print "Normal rotation left" Shift+Tab Previous tab
					Gizmod.Keyboards[0].createEventRaw(GizmoEventType.EV_KEY, GizmoKey.KEY_LEFTSHIFT, 1)
					Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_TAB)
					Gizmod.Keyboards[0].createEventRaw(GizmoEventType.EV_KEY, GizmoKey.KEY_LEFTSHIFT, 0)
				else:
					#print "Normal rotation right" Next tab
					Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_W)
					Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_BACKSPACE)
					Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_TAB)
			else:
				if Event.Value < 0:
					#print "Rotation with button eventvalue < 0" Key . Volume down
                                        Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_COMMA)
					Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_BACKSPACE)   
				else:
					#print "Rotation with button eventvalue > 0" Key , Volume up 
                                        Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_DOT)
					Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_BACKSPACE)
			return True
		#Primary function
		elif self.Primary and Event.Type == GizmoEventType.EV_KEY:
			if Event.Value == 0 and not Gizmo.Rotated:
				Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_E)
				Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_BACKSPACE)
				#print "Button pressed not rotated"
				Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_SPACE)
				Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_BACKSPACE)
				return True
		#Secondary Media function
#		elif not self.Primary and Event.Type == GizmoEventType.EV_REL:
#                        if not Gizmo.getKeyState(GizmoKey.BTN_0):
#                                if Event.Value < 0:
                                        #print "Normal rotation left" Volume Down
#                                        Gizmod.Keyboards[0].createEventRaw(GizmoEventType.EV_KEY, GizmoKey.KEY_LEFTSHIFT, 1)
#                                        Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_COMMA)
#                                        Gizmod.Keyboards[0].createEventRaw(GizmoEventType.EV_KEY, GizmoKey.KEY_LEFTSHIFT, 0)

#                                else:
                                        #print "Normal rotation right" Volume Up
#                                        Gizmod.Keyboards[0].createEventRaw(GizmoEventType.EV_KEY, GizmoKey.KEY_LEFTSHIFT, 1)
#                                        Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_DOT)
#                                        Gizmod.Keyboards[0].createEventRaw(GizmoEventType.EV_KEY, GizmoKey.KEY_LEFTSHIFT, 0)

#                        else:
#                                if Event.Value < 0:
                                        #print "Rotation with button eventvalue < 0" Ctrl+[ -> Prev Track
#                                        Gizmod.Keyboards[0].createEventRaw(GizmoEventType.EV_KEY, GizmoKey.KEY_LEFTCTRL, 1)
#                                        Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_LEFTBRACE)
#                                        Gizmod.Keyboards[0].createEventRaw(GizmoEventType.EV_KEY, GizmoKey.KEY_LEFTCTRL, 0)
#                                else:
                                        #print "Rotation with button eventvalue > 0" Ctrl+] -> Next Track
#                                        Gizmod.Keyboards[0].createEventRaw(GizmoEventType.EV_KEY, GizmoKey.KEY_LEFTCTRL, 1)
#                                        Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_RIGHTBRACE)
#                                        Gizmod.Keyboards[0].createEventRaw(GizmoEventType.EV_KEY, GizmoKey.KEY_LEFTCTRL, 0)
#			return True
		#Secondary Media function 
#		elif not self.Primary and Event.Type == GizmoEventType.EV_KEY:
#                        if Event.Value == 0 and not Gizmo.Rotated:
                                #print "Button pressed not rotated"
#                                Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_P)
#                                return True
		return False

        def onDeviceEventButtonTimeout(self, Gizmo):
                """
                Called when a Powermate's button times out

                This is generated from 200-Powermate-ButtonTimeout.py
                """
		#Ensure Powermate is connected
                if len(Gizmod.Powermates) < 1:
                        print "No Powermate connected"
                        return False	
#		Gizmod.Powermates[0].pulseLED(255,270,2)
		Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_ESC)
		return True
	
	def onDeviceEventEaten(self, Event, Gizmo):
		"""
                Called when a Powermate's button is released after timing out

                This is generated from 200-Powermate-ButtonTimeout.py
                """
		#Ensure Powermate is connected
                if len(Gizmod.Powermates) < 1:
                        print "No Powermate connected"
                        return False

                #print "Button Timeout in [" + self.__class__.__name__ + "] from [" + str(Gizmo.Type) + " " + str(Gizmo.DeviceClassID) + "]"
#		self.Primary = not self.Primary
#		Gizmod.Powermates[0].changeLEDState(0, 255, 2, 0, 0)
#		Gizmod.Keyboards[0].createEventPress(GizmoEventType.EV_KEY, GizmoKey.KEY_ESC) 
                return True

	##############################
	#Private Functions
	##########################

	def __init__(self):
		""" 
		Default Constructor
		"""		
		GizmoScriptRunningApplication.__init__(self, ENABLED, VERSION_NEEDED, INTERESTED_CLASSES, INTERESTED_APPLICATION)
		self.Primary = True
		#Ensure Powermate is connected
                if len(Gizmod.Powermates) > 0:
			Gizmod.Powermates[0].pulseLED(255,250,2)

############################
# PowermateDefault class end
##########################

# register the user script
PowermateRevGui()
if ENABLED:
	if not Gizmod.checkVersion(VERSION_NEEDED, False):
		Gizmod.printNiceScriptInit(1, " * PowermateRevGui", "NOT LOADED", "Version Needed: " + str(VERSION_NEEDED))
	else:
		Gizmod.Dispatcher.userScripts.append(PowermateRevGui())
