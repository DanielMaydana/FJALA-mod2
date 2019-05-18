import React from 'react';
import actions from './actions';
import { connect } from 'react-redux';
import List from '../../../components/List';
import ActionForm from '../../../containers/ActionForm';
import CustomForm from '../../../containers/CustomForm';
import './createPerson.css';

class CreatePerson extends React.Component {

  render() {
    const { personForm } = this.props;
    const actions = [
      {
        text: 'Update',
        type: 'primary',
        icon: 'check_circle',
        onClick: () => {
          console.log('make click');
        },
        dirty: true,
      },
      {
        text: 'Cancel',
        type: 'default',
        icon: 'check_circle',
        onClick: () => {
          console.log('algo');
        },
        dirty: true,
      }
    ];
    const inputs = [
      {
        label: 'Name',
        onChange: this.handleChange,
        objectKey: 'name',
        value: personForm.name,
        type: 'text'
      },
      {
        label: 'Age',
        onChange: this.handleChange,
        objectKey: 'age',
        value: personForm.age,
        type: 'number'
      },
      {
        label: 'Email',
        onChange: this.handleChange,
        objectKey: 'email',
        value: personForm.email,
        type: 'text'
      }
    ];

    const onListItemClick = () => {
      console.log("clicked");
    }

    const musicList = [
      {
        // icon : material
        name : "Josh Homme",
        legend : "The alligator hour",
        action : onListItemClick
      }, {
        
        name : "Leah Shapiro",
        legend : "I want to beleah",
        action : onListItemClick
      }, {
        
        name : "Richie Havens",
        legend : "Electric heavens",
        action : onListItemClick
      }
    ];

    return (
      <div className="create-person-view">
        <ActionForm actions={actions} title={'Update Person'}>
          <CustomForm inputs={inputs} />
        </ActionForm>
        <List actions={musicList}></List>
      </div>
    );
  }

  handleChange = (key, value) => {
    this.props.updateFormPerson({ key, value });
  }

}

const mapStatesToProps = (state) => {
  return {
    personForm: state.createPerson.personForm,
  }
}

const mapDispatchToProps = (dispatch) => {
  return {
    updateFormPerson: (action) => dispatch(actions.UPDATE_FORM_PERSON(action))
  }
}

export default connect(mapStatesToProps, mapDispatchToProps)(CreatePerson);
