#!/usr/bin/node
// ReferenceError


const request = require('request');

const ID = process.argv[2];
const url = `https://swapi.dev/api/films/${ID}/`;
request(url, async function (error, response, body) {
  if (error) {
    console.log(error); // ReferenceError
  } else {
    const characters = JSON.parse(body).characters;
    for (const character of characters) {
      const res = await new Promise((resolve, reject) => {
        request(character, (error, res, html) => {
          if (error) {
            reject(error); // ReferenceRejectError
          } else {
            resolve(JSON.parse(html).name);
          }
        });
      });
      console.log(res); // ReferenceResponse ( HTTP response that an Express app sends when it gets an HTTP request)
    }
  }
});
