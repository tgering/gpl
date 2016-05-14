// updated 2/14/2016

#include "event_manager.h"
#include "gpl_assert.h"
#include "Statement_block.h"
using namespace std;

/* static */ Event_manager *Event_manager::m_instance = 0;

/* static */ Event_manager * Event_manager::instance()
{
  if (!m_instance)
    m_instance = new Event_manager();
  return m_instance;
}

Event_manager::Event_manager()
{
	event_vector.resize(Window::NUMBER_OF_KEYS);
	for(int i = 0; i < event_vector.size(); i++){
		event_vector[i].resize(0);
	}
}

Event_manager::~Event_manager()
{
}

void
Event_manager::add_statement_block(Statement_block *s, Window::Keystroke keystroke){
	event_vector[keystroke].push_back(s);
}

void 
Event_manager::execute_handlers(Window::Keystroke keystroke)
{
	for(int i = 0; i < event_vector[keystroke].size(); i++){
		event_vector[keystroke][i]->execute();
	}
}
