import React, { useEffect, useRef, useState } from 'react';
import { fromEvent } from 'rxjs';
import StepDivider from '../../Utilities/SliderUtilities'
import './style.css';

const SliderMath = require('../../Utilities/SliderUtilities');

function Slider({ steps, size }) {

	const [slider, setSlider] = useState({});
	const [onDragSub, setOndragSub] = useState(null);
	const sliderRef = useRef();
	const mainPoint = useRef();
	const stepBy = 360 / steps;
	const radio = size / 2;

	useEffect(() => {
		setSlider({ stepsData: CreateSteps() });
		subscribe();
		return () => unsubscribe();
	}, []);

	function TranslateElem(elem, x, y) {
		elem.style.transform = `translateX(${x}px) translateY(${y}px)`;
	}

	function CreateSteps() {

		const stepsData = [];
		// TODO: replace the for
		// const stepsData2 = Array.from(Array(steps).keys('a'));
		// console.log(stepsData2);

		for (let index = 0; index < steps; index++) {
			const element = document.createElement('span');
			element.classList.add('step');
			const degree = stepBy * index;
			// I am a genius, please clean my garbage
			const stepPoint = SliderMath.calcCoordinatesFrom(degree, radio);

			stepsData.push({ element, x: stepPoint.x, y: stepPoint.y, degree });
			TranslateElem(element, stepPoint.x, stepPoint.y);
			sliderRef.current.appendChild(element);
			sliderRef.current.style.setProperty('--size', `${size}px`);
		}

		return stepsData;
	}

	console.log(slider, 'slider');

	function subscribe() {

		const $onStart = fromEvent(sliderRef.current, 'mousedown');
		const $onStop = fromEvent(sliderRef.current, 'mouseup');

		$onStart.subscribe(() => subscribeToMouseMove());
		$onStop.subscribe(() => unsubscribeToMouseMove());

		console.log('subscribe');
	}

	function unsubscribe() {
		// I forgot something here... I can't remember what
		console.log('unsubscribe');
	}

	// function CalcDelta

	function calcEventCoordinatesFrom(sliderRef, event) {
		return {
			x: event.x - sliderRef.current.offsetLeft,
			y: event.y - sliderRef.current.offsetTop,
		}
	}

	function calcPositionFromCenter(eventPosition, size) {
		return {
			deltaX: eventPosition.x - (size / 2),
			deltaY: (size / 2) - eventPosition.y
		}
	}

	function subscribeToMouseMove() {
		const $onDrag = fromEvent(sliderRef.current, 'mousemove');
		// oh my this is a mess.
		const subscription = $onDrag.subscribe((e) => {

			const eventPosition = calcEventCoordinatesFrom(sliderRef, e);
			console.log(sliderRef.current.offsetTop, sliderRef.current.offsetLeft, 'aca')
			// const deltaX = eventPosition.x - (size / 2);
			// const deltaY = (size / 2) - eventPosition.y;
			const positionFromCenter = calcPositionFromCenter(eventPosition, size);
			console.log('deltaX:', positionFromCenter.deltaX, ' - deltaY: ', positionFromCenter.deltaY);
			const rad = Math.atan2(positionFromCenter.deltaY, positionFromCenter.deltaX);
			const deg = rad * (180 / Math.PI)
			console.log(deg);
			// const cordinates = calculateFromDeg(eventPosition, size);
			mainPoint.current.style.top = `${eventPosition.y - 12}px`;
			mainPoint.current.style.left = `${eventPosition.x - 12}px`;
		});
		setOndragSub(subscription);
	}

	function calculateFromDeg(deg) {
		// in progrees this is pain in the ... why slider is an empty object
		console.log('slider', slider);
		// performance issue??? mehh it works;
		setSlider(slider => {
			console.log(slider.stepsData, '2');
			console.log(slider)
			// slider.stepsData.forEach(step => {
			// 	console.log(step);
			// });
			return slider;
		});

	}

	function unsubscribeToMouseMove() {
		setOndragSub(subscription => {
			subscription && subscription.unsubscribe()
			return null;
		});
	}

	return (
		<section className="sliderCmpt" ref={sliderRef}>
			<div className="mainPoint" ref={mainPoint}></div>
		</section>
	)
}

Slider.defaultProps = {
	size: 120,
	steps: 2,
}

export default Slider;