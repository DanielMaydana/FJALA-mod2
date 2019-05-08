import React from 'react'
import ActionButton from '../ActionButton';
import './Task.css';

function Task({ title, isDone, toggleDone, index}) {
  const isDoneClass = isDone ? 'is-done' : '';
  const handleClick = () => {
    toggleDone(index, !isDone);
  };

  return (
    <section className={`task-component ${isDoneClass}`}>
      <div className="title"> 
        {title}
      </div>

      <div>
        <ActionButton icon="check_circle" text="Done" type="primary" onClick={handleClick}/>
      </div>
    </section>
  );
}

export default Task;